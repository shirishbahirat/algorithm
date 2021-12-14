#include <iostream>

using namespace std;

int arr[] = {19, 3, 2, 23, 12, 34};

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

  for (int i = 0; i < 6; ++i)
  {
    cout << *(*pparr) << " ";
  }

  cout << endl;

  cout << "running" << endl;

  return 0;
}