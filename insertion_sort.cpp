#include <iostream>

using namespace std;

void sort(int arr[], int size)
{

  for (int i = 1; i < size; ++i)
  {
    int j = (i - 1);
    int x = arr[i];
    while ((arr[j] > x) && (j >= 0))
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = x;
  }
}

int main(int argc, char const *argv[])
{
  int arr[] = {3, 2, 9, 5, 4, 7};
  int size = 6;
  sort(arr, size);

  for (auto i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}