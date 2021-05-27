#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  Solution() : arr{10, 2, 4, 6, 3, 1}, len(5) {}

  void merge(int a[], int lo, int mid, int hi)
  {

    int left[mid - lo + 1];
    int right[hi - lo];
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

  obj->msort(obj->arr, 0, 5);
  return 0;
}
