#include <iostream>
#include <vector>

using namespace std;

int len = 9;
int aarr[] = {10, 9, 8, 3, 6, 5, 4, 7, 2, 1};

void swap(int arr[], int x, int y, int len)
{

  if (x < 0 || y < 0)
    return;
  if (x > len || y > len)
    return;

  if (x != y)
  {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
  }
}

void print(int arr[], int len)
{
  for (int i = 0; i <= len; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int partition(int arr[], int lo, int hi, int len)
{

  int pivot = lo, idx = lo, idy = hi;

  while (idy > idx)
  {
    while (arr[idx] <= arr[pivot] && idx < hi)
      idx++;

    while (arr[idy] > arr[pivot] && idy > lo)
      idy--;

    if (idy > idx)
      swap(arr, idx, idy, len);
  }

  swap(arr, pivot, idy, len);

  return idy;
}

void quick_sort(int arr[], int lo, int hi, int len)
{

  if (hi > lo)
  {
    int mid = partition(arr, lo, hi, len);
    quick_sort(arr, lo, mid, len);
    quick_sort(arr, mid + 1, hi, len);
  }

  return;
}

void bubble_sort(int arr[], int len)
{

  if (len == 0)
    return;

  bool swapped = false;

  for (int j = 0; j < len; j++)
  {
    swapped = false;
    for (int i = 0; i <= len; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        swap(arr, i, i + 1, len);
        swapped = true;
      }
    }
    if (swapped == false)
      return;
  }

  return;
}

void merge(int arr[], int lo, int mid, int hi)
{

  int lena = mid - lo + 1, lenb = hi - mid;

  int left[lena], right[lenb];

  for (int i = 0; i < lena; i++)
    left[i] = arr[lo + i];

  for (int i = 0; i < lenb; i++)
    right[i] = arr[mid + i + 1];

  int i = 0, j = 0, k = lo;

  while (i < lena && j < lenb)
  {
    if (left[i] <= right[j])
    {
      arr[k++] = left[i++];
    }
    else
    {
      arr[k++] = right[j++];
    }
  }

  while (i < lena)
  {
    arr[k++] = left[i++];
  }

  while (j < lenb)
  {
    arr[k++] = right[j++];
  }

  return;
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

  return;
}

int main(int argc, char const *argv[])
{

  // bubble_sort(aarr, len);
  // quick_sort(aarr, 0, len, len);
  merge_sort(aarr, 0, len);
  print(aarr, len);

  return 0;
}