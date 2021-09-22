#include <iostream>

using namespace std;

struct producer_interface;
struct consumer_interface;

struct producer_interface
{
  virtual void transmit(int cmd) {}
  virtual bool ready(void) {}
  // virtual void connect(struct *consumer_interface) {}
};

struct consumer_interface
{
  virtual void receive(int cmd) {}
  virtual bool ready(void) {}
  // virtual void connect(struct *producer_interface) {}
};

int main(int argc, char const *argv[]) { return 0; }