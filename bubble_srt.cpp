#include <iostream>

using namespace std;

void sort(int arr[], int size)
{

  bool swaped = true;
  while (swaped)
  {
    swaped = false;
    for (int i = 1; i < size; ++i)
    {
      if (arr[i - 1] > arr[i])
      {
        int temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
        swaped = true;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int arr[] = {3, 2, 9, 5, 4, 7, 0};
  int size = 7;
  sort(arr, size);

  for (auto i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}