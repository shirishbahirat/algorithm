#include <iostream>

using namespace std;

int partition(int arr[], int lo, int hi);

void swap(int arr[], int idx, int idy)
{
  if (idx != idy)
  {
    int temp = arr[idx];
    arr[idx] = arr[idy];
    arr[idy] = temp;
  }
}

void qsort(int arr[], int lo, int hi)
{
  if (hi > lo)
  {
    int pvt = partition(arr, lo, hi);
    qsort(arr, lo, pvt);
    qsort(arr, pvt + 1, hi);
  }
}

int partition(int arr[], int lo, int hi)
{
  int pivot = lo, i = lo, j = hi;

  while (j > i)
  {
    while (arr[i] <= arr[pivot])
    {
      if (i < hi)
        i++;
    }

    while (arr[j] > arr[pivot])
    {
      if (j > lo)
        j--;
    }

    if (j > i)
      swap(arr, i, j);
  }

  swap(arr, pivot, j);

  return j;
}

int main(int argc, const char *argv[])
{

  int arr[] = {5, 3, 4, 7, 2, 1, 0, 8};
  int len = (sizeof(arr) / sizeof(arr[0])) - 1;

  qsort(arr, 0, len);

  for (int a : arr)
    cout << a << " ";
  cout << endl;

  return 0;
}