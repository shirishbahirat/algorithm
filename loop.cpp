#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int loop(int x)
  {
    vector<int> m(x, 11);
    for (int i : m)
    {
      cout << i << " ";
    }
    cout << endl;
    return 0;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  obj->loop(4);
  return 0;
}
