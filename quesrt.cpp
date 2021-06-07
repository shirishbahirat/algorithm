#include <iostream>

using namespace std;

void swap(int arr[], int idx, int idy)
{
  if (idx != idy)
  {
    int temp = arr[idx];
    arr[idx] = arr[idy];
    arr[idy] = temp;
  }
}

int partition(int arr[], int lo, int hi)
{

  int i = lo, j = hi;

  int pivot = arr[lo];

  while (j > i)
  {
    while (arr[i] <= pivot)
    {
      if (i < hi)
      {
        ++i;
      }
    }

    while (arr[j] > pivot)
    {
      if (j > lo)
      {
        --j;
      }
    }

    if (j > i)
    {
      swap(arr, i, j);
    }
  }

  swap(arr, lo, j);

  return j;
}

void quick_sort(int arr[], int lo, int hi)
{
  if (hi > lo)
  {
    int mid = partition(arr, lo, hi);
    quick_sort(arr, lo, mid);
    quick_sort(arr, mid + 1, hi);
  }

  return;
}

int main(int argc, const char *argv[])
{

  int arr[] = {9, 12, 21, 4, 2, 18, 23};
  int hi = (sizeof(arr) / sizeof(arr[0])) - 1;

  quick_sort(arr, 0, hi);

  for (int b : arr)
    cout << b << " ";
  cout << endl;

  return 0;
}