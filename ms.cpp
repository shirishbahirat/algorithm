#include <iostream>

using namespace std;

void merge(int arr[], int lo, int mid, int hi)
{
  int la = mid - lo + 1;
  int lb = hi - mid;
  int lc = la + lb;

  int idx = 0, idy = 0, idz = 0;

  int ta[la], tb[lb], tc[lc];

  for (int i = lo; i <= mid; i++)
  {
    ta[i] = arr[i];
  }
  for (int i = mid + 1; i <= hi; i++)
  {
    tb[i] = arr[i];
  }
}

void merge_sort(int arr[], int lo, int hi)
{
  if (hi > lo)
  {
    cout << lo << " " << hi << endl;
    int mid = lo + ((hi - lo) / 2);
    merge_sort(arr, lo, mid);
    merge_sort(arr, mid + 1, hi);
  }
}

int main(int argc, char const *argv[])
{

  int arr[] = {9, 4, 3, 7, 6, 5, 10, 1};

  merge_sort(arr, 0, 7);

  return 0;
}