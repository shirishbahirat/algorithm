#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool judgeCircle(string moves)
  {

    int idx = 0;
    int idy = 0;

    for (int i = 0; i < moves.size(); ++i)
    {
      switch (moves[i])
      {
      case 'U':
        idy++;
        break;
      case 'D':
        idy--;
        break;
      case 'L':
        idx--;
        break;
      case 'R':
        idx++;
        break;
      default:
        break;
      }
    }

    if ((idx == 0) and (idy == 0))
      return true;

    return false;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  string moves = "LL";

  cout << obj->judgeCircle(moves) << endl;

  return 0;
}
