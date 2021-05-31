#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  Solution() : a{2, 4, 6, 7}, b{0, 1, 3, 5, 8} {}

  ~Solution() {}

  void merge(void)
  {

    int alen = sizeof(a) / sizeof(a[0]);
    int blen = sizeof(b) / sizeof(b[0]);
    int clen = sizeof(c) / sizeof(c[0]);

    int i = 0, j = 0, k = 0;

    while ((i < alen) && (j < blen))
    {
      if (a[i] <= b[j])
      {
        c[k++] = a[i++];
      }
      else
      {
        c[k++] = b[j++];
      }
    }

    while (i < alen)
    {
      c[k++] = a[i++];
    }

    while (j < blen)
    {
      c[k++] = b[j++];
    }

    for (int x = 0; x < clen; ++x)
    {
      cout << c[x] << " ";
    }
    cout << endl;
    return;
  }

  int a[4], b[5], c[9];
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  obj->merge();

  return 0;
}
