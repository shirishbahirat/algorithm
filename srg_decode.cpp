#include <iostream>

using namespace std;

int main(int argc, char **argv)
{

  cout << argc << endl;

  while (--argc)
  {
    cout << argv[argc] << endl;
  }

  return 0;
}