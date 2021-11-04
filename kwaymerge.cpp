#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

  int a[] = {2, 6, 9, 10};
  int b[] = {1, 3, 5, 7};
  int c[] = {0, 4, 8, 11};

  int asize = sizeof(a) / sizeof(a[0]);
  int bsize = sizeof(b) / sizeof(b[0]);
  int csize = sizeof(c) / sizeof(c[0]);

  int dsize = asize + bsize + csize;

  int d[dsize];

  int ida = 0, idb = 0, idc = 0, idd = 0;

  while ((ida < asize) && (idb < bsize) && (idc < csize))
  {
    ida++;
    idb++;
    idc++;
  }

  return 0;
}