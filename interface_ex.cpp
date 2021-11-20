#include <iostream>

using namespace std;

struct msample
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
msample info = {.data = 1000};
msample *smpl = &info;

int *device_ready_interface(int a)
{
  *x = 10 + a;
  cout << *x << endl;
  return x;
}

msample *get_data(int b)
{
  smpl->data += b;
  return smpl;
}

int main(int argc, char const *argv[])
{
  int m = 20;
  x = &m;
  interface intr = {.device_ready = device_ready_interface,
                    .device_attached = nullptr};

  x = intr.device_ready(200);

  cout << get_data(11)->data << endl;

  return 0;
}