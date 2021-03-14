#include <iostream>
using namespace std;

void insert(int *array, int element, int size)
{

  for (int i = size; i > 0; --i)
  {
    int *temp = array;
    cout << *array << endl;
    --array;
    if (*array > element)
    {
      *temp = *array;
    }
    else
    {
      *temp = element;
      break;
    }
  }
}

int main(int argc, char const *argv[])
{

  int array[] = {1, 2, 3, 5, 6, 7, 8, 9, 10, 0};
  int element = 4;
  int size = 10;

  insert(&array[9], element, size);

  for (int i : array)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}