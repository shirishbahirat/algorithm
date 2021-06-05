#include <iostream>

using namespace std;

void merge(int arr[], int lo, int mid, int hi) { return; }

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