#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {

    int n = s.size();

    cout << n << " " << s[n - 2] << endl;

    return 0;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  string s = "Hello World";

  obj->lengthOfLastWord(s);

  return 0;
}
