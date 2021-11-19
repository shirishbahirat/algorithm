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
  int m = 20;
  x = &m;
  interface intr = {.device_ready = device_ready_interface};

  x = intr.device_ready(200);

  return 0;
}