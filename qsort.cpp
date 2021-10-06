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
      if ((idx >= lo) && (idx <= hi))
        if ((idy >= lo) && (idy <= hi))
          swap(arr, idx, idy);
    }
  }

  cout << idx << " " << hi << endl;

  if ((idx >= lo) && (idx <= hi))
    swap(arr, idx, hi);

  if (idx >= lo)
    return idx;
  else
    return lo;
}

void aprint(int arr[])
{
  for (int x : arr)
  {
    cout << x << " ";
  }
  cout << endl;
}

void quick_sort(int arr[], int lo, int hi, int idx)
{
  idx--;
  aprint(arr);

  if ((hi > lo) && (idx > 0))
  {
    int mid = partition(arr, lo, hi);
    quick_sort(arr, lo, mid, idx);
    quick_sort(arr, mid + 1, hi, idx);
  }

  return;
}

int main(int argc, char const *argv[])
{
  int arr[] = {3, 4, 7, 2, 10, 0, 1, 5, 8, 9, 11, 6};
  int size = (sizeof(arr) / sizeof(arr[0])) - 1;
  int index = 10;

  quick_sort(arr, 0, size, index);

  aprint(arr);

  return 0;
}