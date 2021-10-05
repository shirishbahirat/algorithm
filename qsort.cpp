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

  int pivot = arr[hi];
  int idx = lo, idy = hi;

  while (lo < hi)
  {
    while (arr[idx] < pivot)
      idx++;
    while (arr[idy] >= pivot)
      idy--;

    if (idx > idy)
    {
      swap(arr, idx, idy);
    }
  }

  return
}

void quick_sort(int arr[], int lo, int hi)
{

  if (hi > lo)
  {
    int mid = partition(arr, lo, hi);
  }

  return;
}

int main(int argc, char const *argv[])
{
  int arr[] = {3, 4, 7, 2, 10, 1, 5, 8, 9, 11, 6};
  int size = -1 + sizeof(arr) / sizeof(arr[0]);

  quick_sort(arr, 0, size);

  return 0;
}