#include <iostream>
using namespace std;

typedef int (*funct)(int);

struct vf
{
  union
  {
    struct
    {
      int data;
    } pp;
    struct
    {
      int ndata;
    };
  };
};

struct api
{
  funct send[10];
};

int sent(int data)
{
  cout << "from api " << data << endl;
  return 0;
}

int main(int argc, char const *argv[])
{

  api vm = {.send[0] = &sent};
  vf nc;

  nc.pp.data = 11000;
  vm.send[0](100);
  cout << nc.pp.data << " " << nc.ndata << endl;
  nc.ndata = 3100;
  cout << nc.pp.data << " " << nc.ndata << endl;
  return 0;
}