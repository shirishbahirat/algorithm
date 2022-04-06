#include <iostream>

using namespace std;

int arr[] = {19, 3, 2, 23, 12, 34};

//////
void print_arr(int **p, int len)
{

  for (int i = 0; i < len; ++i)
  {
    cout << *(*p) << " ";
    (*p)++;
  }

  cout << endl;
  return;
}

int main(int argc, const char *argv[])
{

  int **pparr;
  int *parr;

  parr = arr;
  pparr = &parr;

  for (int i = 0; i < 6; ++i)
  {
    cout << *parr << " ";
    parr++;
  }

  cout << endl;

  parr = arr;
  for (int i = 0; i < 6; ++i)
  {
    cout << *(*pparr) << " ";
    (*pparr)++;
  }

  cout << endl;

  parr = arr;
  for (int i = 0; i < 6; ++i)
  {
    cout << *(*pparr) << " ";
    (*pparr)++;
  }

  parr = arr;
  cout << endl;

  cout << "running" << endl;

  print_arr(pparr, 6);

  return 0;
}