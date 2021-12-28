#include <iostream>

using namespace std;

char arr[] = {'a', 'b', 'c', 'd'};
int irr[] = {10, 11, 12, 9};

int main(int argc, char **argv)
{

  int decode = 1;
  char *parr = arr;
  char **pparr = &parr;

  cout << pparr[0][0] << endl;
  cout << pparr[0][1] << endl;
  cout << pparr[0][2] << endl;
  cout << pparr[0][3] << endl;

  cout << argc << endl;

  while (--argc)
  {
    cout << argv[decode] << endl;
    decode++;
  }

  return 0;
}