#include <iostream>

using namespace std;

int main(int argc, char **argv)
{

  cout << argc << endl;

  int decode = 1;

  while (--argc)
  {
    cout << argv[decode] << endl;
    decode++;
  }

  return 0;
}