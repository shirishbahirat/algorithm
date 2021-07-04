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

int main(int argc, char const *argv[])
{

  bubble_sort(aarr, len);
  print(aarr, len);

  return 0;
}