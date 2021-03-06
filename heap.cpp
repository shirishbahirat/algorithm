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

void trickle_up(int arr[], int position)
{

  if (!position)
    return;

  int parent = (position - 1) / 2;

  if (arr[position] > arr[parent])
  {
    swap(arr, position, parent);
    trickle_up(arr, parent);
  }

  return;
}

void trickle_down(int arr[], int position, int length)
{

  int left = 2 * position + 1;
  int right = 2 * position + 2;

  int largest = position;

  if (left < length && arr[left] > arr[largest])
  {
    largest = left;
  }

  if (right < length && arr[right] > arr[largest])
  {
    largest = right;
  }

  if (largest != position)
  {
    swap(arr, position, largest);
    trickle_down(arr, largest, length);
  }
}

void heapify(int arr[], int len)
{
  int parent = len / 2 - 1;

  for (int i = parent; i >= 0; --i)
  {
    trickle_down(arr, i, len);
  }

  for (int i = len - 1; i >= 0; i--)
  {
    swap(arr, 0, i);
    trickle_down(arr, 0, i);
  }

  return;
}

int main(int argc, const char *argv[])
{

  int arr[] = {1, 12, 9, 5, 6, 10};
  int len = sizeof(arr) / sizeof(arr[0]);

  trickle_up(arr, 3);

  heapify(arr, len);

  for (int a : arr)
    cout << a << " ";
  cout << endl;

  return 0;
}