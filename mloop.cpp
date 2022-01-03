#include <iostream>

using namespace std;

int arr[] = {9, 4, 7, 2, 3, 8, 4};

struc node
{
  int data;
  node *left;
  node *right;
};

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

void lsum(int arr[], int idx)
{
  for (int i = 0; i <= idx; ++i)
  {
    sum += arr[i];
    cout << sum << " " << i << endl;
  }
}

void btree(int idx)
{

  int l = 2 * idx + 1;
  int r = 2 * idx + 2;

  cout << l << " " << r << endl;

  return;
}

int main(int argc, const char *argv[])
{

  rsum(arr, 6);

  cout << sum << endl;

  sum = 0;
  lsum(arr, 6);
  cout << sum << endl;

  btree(0);
  btree(1);
  btree(2);

  return 0;
}