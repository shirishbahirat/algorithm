#include <iostream>

using namespace std;

char arr[] = {'a', 'b', 'c'};

int main(int argc, char **argv)
{

  cout << argc << endl;

  int decode = 1;
  char **parr = &arr;

  while (--argc)
  {
    cout << argv[decode] << endl;
    decode++;
  }

  return 0;
}