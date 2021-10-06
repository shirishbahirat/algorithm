#include <iostream>

using namespace std;

void swap(int arr[], int x, int y)
{

  if (x == y)
    return;

  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;

  return;
}

int partition(int arr[], int lo, int hi)
{

  cout << "in" << endl;
  int pivot = arr[hi];
  int idx = lo, idy = hi;

  while (idx < idy)
  {
    while (arr[idx] < pivot)
    {
      if (idx < hi)
        idx++;
    }

    while (arr[idy] >= pivot)
    {
      if (idy > lo)
        idy--;
    }

    if (idx < idy)
    {
      swap(arr, idx, idy);
    }
  }

  cout << idx << " " << hi << endl;

  swap(arr, idx, hi);

  return idx;
}

void aprint(int arr[], int len)
{
  for (int i = 0; i <= len; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void quick_sort(int arr[], int lo, int hi, int idx, int len)
{
  idx--;
  aprint(arr, len);

  if (hi > lo)
  {
    int mid = partition(arr, lo, hi);
    quick_sort(arr, lo, mid, idx, len);
    quick_sort(arr, mid + 1, hi, idx, len);
  }

  return;
}

int main(int argc, char const *argv[])
{
  // int arr[] = {3, 4, 7, 2, 10, 0, 1, 5, 8, 9, 11, 6 };
  int arr[] = {3, 4, 7, 2};
  int size = (sizeof(arr) / sizeof(arr[0])) - 1;
  int index = 4;

  quick_sort(arr, 0, size, index, size);

  aprint(arr, size);

  return 0;
}