#include <iostream>
#include <vector>

using namespace std;

struct producer_interface;
struct consumer_interface;

struct producer_interface
{
  virtual void transmit(int cmd) = 0;
  virtual bool ready(void) = 0;
  virtual void connect(consumer_interface *cons) = 0;
};

struct consumer_interface
{
  virtual void receive(int cmd) = 0;
  virtual bool ready(void) = 0;
  virtual void connect(producer_interface *prod) = 0;
};

class logger
{
public:
  logger(string n) : name(n), count(0) {}
  ~logger() {}

  virtual string get_name(void) { return name; }

private:
  string name;
  int count;
};

class channel
{
public:
  channel(int d) : id(d) {}
  ~channel() {}

private:
  int id;
};

class media
{
public:
  media(int d) : id(d) {}
  ~media() {}

  void op() { cout << "From " << id << endl; }

private:
  int id;
};

class producer : public producer_interface, public logger
{
public:
  producer(string n)
      : logger("producer"), counter(0), tx_ready(false), consumer(nullptr),
        name(n)
  {
  }
  ~producer() {}

  virtual void transmit(int cmd) { consumer->ready(); };
  virtual bool ready(void)
  {
    cout << "from producer " << get_name() << endl;
    return false;
  }
  virtual void connect(consumer_interface *cons)
  {
    assert(cons);
    consumer = cons;
  }

private:
  int counter;
  bool tx_ready;
  consumer_interface *consumer;
  string name;
};

class consumer : public consumer_interface, public logger
{
public:
  consumer(string n, int d, int c)
      : logger("consumer"), counter(0), rx_ready(false), producer(nullptr),
        name(n), dies(d), chns(c)
  {
    for (int i = 0; i < dies; ++i)
    {
      mx.push_back(new media(i));
    }
  }
  ~consumer() {}

  virtual void receive(int cmd)
  {
    producer->ready();

    for (int i = 0; i < dies; ++i)
    {
      mx[i]->op();
    }
  }

  virtual bool ready(void)
  {
    cout << "from consumer " << get_name() << endl;
    return false;
  }
  virtual void connect(producer_interface *prod)
  {
    assert(prod);
    producer = prod;
  }

  virtual void task(int id) { mx[id]->op(); }

private:
  int counter;
  bool rx_ready;
  producer_interface *producer;
  string name;
  int dies;
  int chns;
  vector<media *> mx;
  vector<channel *> ch;
};

int main(int argc, char const *argv[])
{

  producer_interface *p = new producer("producer");
  consumer_interface *c = new consumer("consumer", 8, 4);

  p->connect(c);
  c->connect(p);

  p->transmit(10);
  c->receive(10);

  return 0;
}