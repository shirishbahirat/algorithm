#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string removeOuterParentheses(string S)
  {

    int counter = 0;
    string result = "";
    for (int i = 0; i < S.size(); i++)
    {
      char c = S[i];
      if (c == '(' && counter++ > 0)
      {
        result = result + c;
      }
      if (c == ')' && counter-- > 1)
      {
        result = result + c;
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  string S = "(()())(())";

  cout << obj->removeOuterParentheses(S) << endl;

  return 0;
}
