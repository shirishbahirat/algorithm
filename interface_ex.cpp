#include <iostream>

using namespace std;

typedef struct inf
{
  int *(*device_ready)(int);
} interface;

int *x;

int *device_ready_interface(int a)
{
  *x = 10 + a;
  cout << *x << endl;
  return x;
}

int main(int argc, char const *argv[])
{

  //*x = 20;
  // interface intr = {.device_ready = device_ready_interface};

  return 0;
}