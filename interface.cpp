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

class media
{
public:
  media(int d) : id(d) {}
  ~media() {}

  void op() { cout << "From " << id << endl; }

private:
  int id;
};

class producer : public producer_interface
{
public:
  producer(string n) : counter(0), tx_ready(false), consumer(nullptr), name(n)
  {
  }
  ~producer() {}

  virtual void transmit(int cmd) { consumer->ready(); };
  virtual bool ready(void)
  {
    cout << "from producer" << endl;
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

class consumer : public consumer_interface
{
public:
  consumer(string n) : counter(0), rx_ready(false), producer(nullptr), name(n)
  {
  }
  ~consumer() {}

  virtual void receive(int cmd) { producer->ready(); };
  virtual bool ready(void)
  {
    cout << "from consumer" << endl;
    return false;
  }
  virtual void connect(producer_interface *prod)
  {
    assert(prod);
    producer = prod;
  }

private:
  int counter;
  bool rx_ready;
  producer_interface *producer;
  string name;
};

int main(int argc, char const *argv[])
{

  producer_interface *p = new producer("producer");
  consumer_interface *c = new consumer("consumer");

  p->connect(c);
  c->connect(p);

  p->transmit(10);
  c->receive(10);

  media *m[5];

  for (int i = 0; i < 5; ++i)
  {
    m[i] = new media(i);
  }

  return 0;
}