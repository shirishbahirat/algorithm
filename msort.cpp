#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  Solution() : arr{23, 16, 34, 22, 17, 32, 11, 25} {}

  void prnt(int arr[])
  {
    for (int i = 0; i < 8; ++i)
    {
      cout << arr[i] << " ";
    }
    cout << endl;

    return;
  }

  void merge(int a[], int lo, int mid, int hi)
  {

    int s1 = mid - lo + 1;
    int s2 = hi - mid;

    int left[s1], right[s2];

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

    cout << "msort " << lo << " " << hi << endl;

    if (lo < hi)
    {

      int mid = lo + ((hi - lo) / 2);

      msort(a, lo, mid);
      msort(a, mid + 1, hi);

      cout << "merge " << lo << " " << mid << " " << hi << endl;

      merge(a, lo, mid, hi);

      prnt(a);
    }

    return;
  }

  int arr[];
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  obj->msort(obj->arr, 0, 7);

  obj->prnt(obj->arr);

  return 0;
}
