#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  Solution() : arr{10, 2, 4, 6, 3, 1, 7}, len(6) {}

  void merge(int a[], int lo, int mid, int hi)
  {

    int s1 = mid - lo + 1;
    int s2 = hi - lo;

    int left[s1];
    int right[hi - lo];

    for (int i = 0; i < s1; ++i)
      left[i] = a[lo + i];

    for (int i = 0; i < s2; ++i)
      right[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = lo;

    while (i < s1 && j < s2)
    {
      if (left[i] <= right[j])
      {
        a[k++] = left[i++];
      }
      else
      {
        a[k++] = right[j++];
      }
    }
    while (i < s1)
    {
      a[k++] = left[i++];
    }
    while (j < s2)
    {
      a[k++] = right[j++];
    }
  }

  void msort(int a[], int lo, int hi)
  {

    cout << lo << " " << hi << endl;

    if (lo < hi)
    {

      int mid = lo + ((hi - lo) / 2);

      msort(a, lo, mid);
      msort(a, mid + 1, hi);

      merge(a, lo, mid, hi);
    }

    return;
  }

  int len;
  int arr[];
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  obj->msort(obj->arr, 0, 6);

  for (int i = 0; i < 6; ++i)
  {
    cout << obj->arr[i] << " ";
  }
  cout << endl;

  return 0;
}
