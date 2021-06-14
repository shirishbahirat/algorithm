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

void trickle_down_min(int arr[], int position, int length)
{

  int largest = position;

  int left = position * 2 + 1;
  int right = position * 2 + 2;

  if ((left < length) && (arr[left] > arr[largest]))
    largest = left;

  if ((right < length) && (arr[right] > arr[largest]))
    largest = right;

  if (largest != position)
  {
    swap(arr, largest, position);
    trickle_down_min(arr, largest, length);
  }

  return;
}

void heap_sort_min(int arr[], int len)
{

  int parent = len / 2 - 1;
  for (int i = parent; i >= 0; --i)
  {
    trickle_down_min(arr, i, len);
  }

  for (int i = len - 1; i >= 0; --i)
  {
    swap(arr, 0, i);
    trickle_down_min(arr, 0, i);
  }

  return;
}

int main(int argc, const char *argv[])
{

  int arr[] = {8, 4, 3, 2, 7, 1, 11};
  int len = sizeof(arr) / sizeof(arr[0]);

  heap_sort_min(arr, len);

  for (int a : arr)
    cout << a << " ";
  cout << endl;

  return 0;
}