#include <iostream>

using namespace std;

int arr[] = {9, 4, 7, 2, 3, 8, 4};

int sum = 0;

void rsum(int arr[], int idx)
{

  sum = sum + arr[idx];

  cout << sum << " " << idx << endl;

  if (idx == 0)
    return;
  else
    rsum(arr, --idx);

  cout << idx + 1 << endl;

  return;
}

int main(int argc, const char *argv[])
{

  rsum(arr, 6);

  cout << sum << endl;

  return 0;
}