#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

  int a[] = {2, 6, 9, 10};
  int b[] = {1, 3, 5, 7};
  int c[] = {0, 4, 8, 11};

  int size = sizeof(a) / sizeof(a[0]);
  size += sizeof(b) / sizeof(b[0]);
  size += sizeof(c) / sizeof(c[0]);

  int d[size];

  return 0;
}