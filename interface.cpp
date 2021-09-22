#include <iostream>

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

class producer : public producer_interface
{
public:
  producer() : counter(0), tx_ready(false) {}
  ~producer() {}

  virtual void transmit(int cmd){};
  virtual bool ready(void) { return false; }
  virtual void connect(consumer_interface *cons) {}

private:
  int counter;
  bool tx_ready;
};

class consumer : public consumer_interface
{
public:
  consumer() : counter(0), rx_ready(false) {}
  ~consumer() {}

  virtual void receive(int cmd){};
  virtual bool ready(void) { return false; }
  virtual void connect(producer_interface *prod) {}

private:
  int counter;
  bool rx_ready;
  producer_interface *producer;
};

int main(int argc, char const *argv[]) { return 0; }