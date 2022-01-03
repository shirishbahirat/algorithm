#include <iostream>

using namespace std;

int arr[] = {9, 4, 7, 2, 3, 8, 4};

int sum = 0;

int rsum(int arr[], int idx, int sum)
{

  sum = sum + arr[idx];

  cout << sum << endl;

  if (idx == 0)
    return sum;
  else
    rsum(arr, --idx, sum);

  return sum;
}

int main(int argc, const char *argv[])
{

  sum = rsum(arr, 6, sum);

  cout << sum << endl;

  return 0;
}