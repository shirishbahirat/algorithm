#include <iostream>

using namespace std;

void merge(int arr[], int lo, int mid, int hi)
{

  int s1 = mid - lo + 1;
  int s2 = hi - mid;

  int left[s1], right[s2];

  for (int i = 0; i < s1; ++i)
    left[i] = arr[lo + i];

  for (int i = 0; i < s2; ++i)
    right[i] = arr[mid + 1 + i];

  int i = 0, j = 0, k = lo;

  while ((i < s1) && (j < s2))
  {
    if (left[i] < right[j])
    {
      arr[k++] = left[i++];
    }
    else
    {
      arr[k++] = right[j++];
    }
  }

  while (i < s1)
    a[k++] = left[i++];

  while (j < s2)
    a[k++] = right[j++];

  return;
}

void msort(int arr[], int lo, int hi)
{

  if (hi > lo)
  {
    int mid = lo + (hi - lo) / 2;

    msort(arr, lo, mid);
    msort(arr, mid + 1, hi);
  }

  return;
}

int main(int argc, const char *argv[])
{

  int arr[] = {6, 4, 3, 2, 1, 7, 9, 8};
  int hi = (sizeof(arr) / sizeof(arr[0])) - 1;

  msort(arr, 0, hi);

  return 0;
}