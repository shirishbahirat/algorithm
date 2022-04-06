#include "systemc.h"
#include <iostream>

/**

---------------------------------------------------------------------
Configuration summary of SystemC 2.3.3 for x86_64-apple-darwin21.4.0
---------------------------------------------------------------------

 Directory setup (based on classic layout):
   Installation prefix (aka SYSTEMC_HOME):
      /Users/shirishbahirat/Documents/bootsim/systemc-2.3.3
   Header files  : <SYSTEMC_HOME>/include
   Libraries     : <SYSTEMC_HOME>/lib-macosx64
   Documentation : <SYSTEMC_HOME>/docs
   Examples      : <SYSTEMC_HOME>/examples

 Architecture    : macosx64
 Compiler        : g++ (C/C++)

 Build settings:
   Enable compiler optimizations  : yes
   Include debugging symbols      : no
   Coroutine package for processes: QuickThreads
   Enable VCD scopes by default   : yes
   Disable async_request_update   : no
   Phase callbacks (experimental) : no

---------------------------------------------------------------------
Shirishs-MBP:objdir shirishbahirat$ echo $SYSTEMC_HOME
/Users/shirishbahirat/Documents/bootsim/systemc-2.3.3/
Shirishs-MBP:objdir shirishbahirat$

 */

#include <systemc.h>

class scx_mutex_w_policy : public sc_mutex
{
public:
  enum policy_type
  {
    FIFO,
    RANDOM
  };

  explicit scx_mutex_w_policy(policy_type policy) : policy_(policy) {}

  virtual int lock()
  {
    if (in_use())
    {
      sc_event my_event;
      event_list.push_back(&my_event);
      wait(my_event);
    }

    m_owner = sc_get_current_process_b();
    return 0;
  }

  virtual int unlock()
  {
    if (m_owner != sc_get_current_process_b())
      return -1;

    m_owner = 0;
    sc_event *e = next_event();
    if (e)
      e->notify();

    return 0;
  }

private:
  sc_event *next_event()
  {
    if (event_list.empty())
      return 0;

    if (policy_ == FIFO)
    {
      return event_list.pop_front();
    }
    else
    { // RANDOM
      sc_plist_iter<sc_event *> ev_itr(&event_list);
      int index = rand() % event_list.size();
      for (int i = 0; i < index; i++)
        ev_itr++;

      sc_event *e = ev_itr.get();
      ev_itr.remove();
      return e;
    }
  }

  sc_plist<sc_event *> event_list;
  policy_type policy_;
};

class top : public sc_module
{
public:
  SC_HAS_PROCESS(top);

  top(sc_module_name name) : sc_module(name), mutex_(scx_mutex_w_policy::FIFO)
  {
    SC_THREAD(t1);
    SC_THREAD(t2);
    SC_THREAD(t3);
  }

  void t1()
  {
    wait(1, SC_NS);
    mutex_.lock();
    cout << "t1 got mutex at " << sc_time_stamp() << endl;
    wait(10, SC_NS);
    mutex_.unlock();
  }

  void t2()
  {
    wait(2, SC_NS);
    mutex_.lock();
    cout << "t2 got mutex at " << sc_time_stamp() << endl;
    wait(10, SC_NS);
    mutex_.unlock();
  }

  void t3()
  {
    wait(3, SC_NS);
    mutex_.lock();
    cout << "t3 got mutex at " << sc_time_stamp() << endl;
    wait(10, SC_NS);
    mutex_.unlock();
  }

private:
  scx_mutex_w_policy mutex_;
};

int sc_main(int, char *[])
{
  top top1("Top1");
  sc_start(1000, SC_NS);
  cout << endl << endl;
  return 0;
}
