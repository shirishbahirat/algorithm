#include <iostream>
using namespace std;

typedef int (*function)(int);

struct api
{
  function send;
};

int send(int data)
{

  cout << "from api " << data << endl;

  return 0;
}

int main(int argc, char const *argv[])
{

  api vm = {.function = send;
};

return 0;
}