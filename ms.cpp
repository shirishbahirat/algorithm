#include <iostream>

using namespace std;

void merge(int arr[], int lo, int mid, int hi)
{
  int la = mid - lo + 1;
  int lb = hi - mid;

  int idx = 0, idy = 0, idz = lo;

  int ta[la], tb[lb];

  for (int i = lo, j = 0; i <= mid; i++, j++)
  {
    ta[j] = arr[i];
  }

  for (int i = mid + 1, j = 0; i <= hi; i++, j++)
  {
    tb[j] = arr[i];
  }

  while ((idx < la) && (idy < lb))
  {
    if (arr[idx] <= tb[idy])
    {
      arr[idz++] = ta[idx++];
    }
    else
    {
      arr[idz++] = tb[idy++];
    }
  }

  while (idx < la)
  {
    arr[idz++] = ta[idx++];
  }

  while (idx < lb)
  {
    arr[idz++] = tb[idy++];
  }
}

void merge_sort(int arr[], int lo, int hi)
{
  if (hi > lo)
  {
    int mid = lo + ((hi - lo) / 2);
    merge_sort(arr, lo, mid);
    merge_sort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
  }
}

int main(int argc, char const *argv[])
{

  int arr[] = {9, 4, 3, 7, 6, 5, 10, 1};

  merge_sort(arr, 0, 7);

  for (auto x : arr)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}