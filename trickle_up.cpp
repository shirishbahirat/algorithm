#include <iostream>
#include <vector>

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

void trickle_up(int arr[], int idx)
{
  if (idx > 0)
  {
    int p = (idx - 1) / 2;
    if (arr[idx] > arr[p])
    {
      swap(arr, idx, p);
      trickle_up(arr, p);
    }
  }

  return;
}

int main(int argc, char const *argv[])
{

  int arr[] = {10, 8, 6, 5, 7, 4, 12};
  int len = sizeof(arr) / sizeof(arr[0]);

  trickle_up(arr, len - 1);

  print(arr, len);

  return 0;
}