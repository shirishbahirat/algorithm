#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {

    int n = s.size();
    int last = 0;
    int first = 0;

    while (n--)
    {
      if ((last == 0) && (s[n] = !' '))
        last = n;

      if ((first == 0) && (s[n] < last) && (s[n] == ' '))
      {
        first = n;
        return (last - first);
      }
    }

    return 0;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  string s = "Hello World";

  cout << obj->lengthOfLastWord(s) << endl;

  return 0;
}
