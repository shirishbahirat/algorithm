#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  Solution() : arr{6, 5, 4, 1, 2, 8, 3, 9} {}

  void msort(int arr[], int lo, int mid, int hi)
  {

    int ln = mid - lo + 1;
    int lm = hi - mid;

    int left[ln], right[lm];

    for (int i = 0; i < ln; ++i)
    {
      left[i] = arr[lo + i];
    }

    for (int i = 0; i < lm; ++i)
    {
      right[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = lo;

    while ((i < ln) && (j < lm))
    {
      if (left[i] <= right[j])
      {
        arr[k++] = left[i++];
      }
      else
      {
        arr[k++] = right[j++];
      }
    }

    while (i < ln)
    {
      arr[k++] = left[i++];
    }

    while (j < lm)
    {
      arr[k++] = right[j++];
    }

    return;
  }

  void merge(int arr[], int lo, int hi)
  {

    if (hi > lo)
    {
      int mid = lo + ((hi - lo) / 2);
      merge(arr, lo, mid);
      merge(arr, mid + 1, hi);
      msort(arr, lo, mid, hi);
    }
  }

  void sort(void)
  {

    merge(arr, 0, 7);

    for (int i = 0; i <= 7; ++i)
    {
      cout << arr[i] << " ";
    }

    cout << endl;

    return;
  }

  int arr[];
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  obj->sort();

  return 0;
}
