#include <iostream>

using namespace std;

char arr[] = {'a', 'b'};

int main(int argc, char **argv)
{

  int decode = 1;
  char *parr = arr;
  char **pparr = &parr;

  cout << pparr[0] << endl;

  cout << argc << endl;

  while (--argc)
  {
    cout << argv[decode] << endl;
    decode++;
  }

  return 0;
}