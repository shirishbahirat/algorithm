#include <iostream>

using namespace std;

struct producer_interface;
struct consumer_interface;

struct producer_interface
{
  virtual void transmit(int cmd) = 0;
  virtual bool ready(void);
  virtual void connect(consumer_interface *cons);
};

struct consumer_interface
{
  virtual void receive(int cmd);
  virtual bool ready(void);
  virtual void connect(producer_interface *prod);
};

int main(int argc, char const *argv[]) { return 0; }