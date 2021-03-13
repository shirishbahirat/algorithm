#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void pattern(int x, int y)
  {

    for (int i = 0; i < x; ++i)
    {
      for (int j = 0; j < y; ++j)
      {
        if (i + j > 4 - 1)
          cout << "*";
        else
          cout << " ";
      }
      cout << endl;
    }

    return;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  obj->pattern(4, 4);

  return 0;
}
