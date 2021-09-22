#include <iostream>

using namespace std;

struct producer_interface;
struct consumer_interface;

struct producer_interface
{
  virtual void transmit(int cmd) = 0;
  virtual bool ready() = 0;
  virtual void connect(struct *consumer_interface) = 0;
};

struct consumer_interface
{
  virtual void receive(int cmd) = 0;
  virtual bool ready() = 0;
  virtual void connect(struct *producer_interface) = 0;
};

int main(int argc, char const *argv[]) { return 0; }