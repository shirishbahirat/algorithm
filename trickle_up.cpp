#include <iostream>

using namespace std;

void swap(int arr[], int a, int b)
{
  if (a != b)
  {
    arr[a] ^= arr[b] ^= arr[a] ^= arr[b];
  }
}

void print(int arr[], int len)
{
  for (int i = 0; i < len; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[])
{

  int arr[] = {10, 8, 6, 5, 7, 4, 12};
  int len = sizeof(arr) / sizeof(arr[0]);

  print(arr, len);

  return 0;
}