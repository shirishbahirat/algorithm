#include <iostream>

using namespace std;

char arr[] = {'a', 'b', 'c'};

int main(int argc, char **argv)
{

  cout << argc << endl;

  int decode = 1;
  char *parr = arr;
  char **pparr = &parr;

  cout << pparr[0] << endl;

  while (--argc)
  {
    cout << argv[decode] << endl;
    decode++;
  }

  return 0;
}