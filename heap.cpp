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
}

void trickle_down(int arr[], int position, int length)
{

  int left = 2 * position + 1;
  int right = 2 * position + 2;

  int largest = position;
}

int main(int argc, const char *argv[])
{

  int arr[] = {4, 2, 3, 6};

  trickle_up(arr, 3);

  for (int a : arr)
    cout << a << " ";
  cout << endl;

  return 0;
}