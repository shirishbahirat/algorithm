#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string removeOuterParentheses(string S) { return S; }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  string S = "(()())(())";

  cout << obj->removeOuterParentheses(S) << endl;

  return 0;
}
