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

void trickle_down(int arr[], int idx, int len)
{

  int largest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if ((arr[largest] > arr[left]) && (left < len))
    largest = left;

  if ((arr[largest] > arr[right]) && (right < len))
    largest = right;

  if (largest != idx)
  {
    swap(arr, idx, largest);
    trickle_down(arr, largest, len);
  }
}

int main(int argc, char const *argv[])
{
  int arr[] = {10, 4, 6, 8, 7, 8, 9};
  int len = sizeof(arr) / sizeof(arr[0]);

  trickle_down(arr, 0, len);

  for (int a : arr)
    cout << a << " ";

  cout << endl;

  return 0;
}