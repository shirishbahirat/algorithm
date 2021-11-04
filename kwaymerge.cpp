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

  for (int i = 0; i < dsize; ++i)
  {
    d[i] = 111;
  }

  int ida = 0, idb = 0, idc = 0, idd = 0;

  while ((ida < asize) && (idb < bsize) && (idc < csize))
  {
    if ((a[ida] < b[idb]) && (a[ida] < c[idc]))
    {
      d[idd++] = a[ida++];
    }
    else if ((b[idb] < a[ida]) && (b[idb] < c[idc]))
    {
      d[idd++] = b[idb++];
    }
    else if ((c[idc] < a[ida]) && (c[idc] < b[idb]))
    {
      d[idd++] = c[idc++];
    }
  }

  if (ida == asize)
  {

    while ((idb < bsize) && (idc < csize))
    {
      if (b[idb] < c[idc])
      {
        d[idd++] = b[idb++];
      }
      else
      {
        d[idd++] = c[idc++];
      }
    }
  }

  if (idb == bsize)
    cout << "b" << endl;

  if (idc == csize)
    cout << "c" << endl;

  for (int i = 0; i < dsize; ++i)
  {
    cout << d[i] << " ";
  }
  cout << endl;

  return 0;
}