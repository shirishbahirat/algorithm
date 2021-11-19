#include <iostream>

using namespace std;

struct sample
{
  int data;
};

typedef struct inf
{
  int *(*device_ready)(int);
  int *(*device_attached)(int);
  void *(*unused1)();
  void *(*unused2)();
} interface;

int *x;
sample info = {.data = 1000};
sample *smpl = &info;

int *device_ready_interface(int a)
{
  *x = 10 + a;
  cout << *x << endl;
  return x;
}

sample *get_data() { return smpl; }

int main(int argc, char const *argv[])
{
  int m = 20;
  x = &m;
  interface intr = {.device_ready = device_ready_interface,
                    .device_attached = nullptr};

  x = intr.device_ready(200);

  return 0;
}