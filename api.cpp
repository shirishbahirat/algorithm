#include <iostream>
using namespace std;

typedef int (*funct)(int);

struct api
{
  funct send[];
};

int sent(int data)
{

  cout << "from api " << data << endl;

  return 0;
}

int main(int argc, char const *argv[])
{

  // api vm = {.send[0] = &sent};

  // vm.send(100);

  return 0;
}