#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int calculateTime(string keyboard, string word)
  {
    vector<int> check(26, 0);
    for (int i = 0; i < keyboard.size(); i++)
    {
      check[keyboard[i] - 'a'] = i;
    }

    int ret = 0;
    int now = 0;
    for (int i = 0; i < word.size(); i++)
    {
      ret += abs(now - check[word[i] - 'a']);
      now = check[word[i] - 'a'];
    }
    return ret;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  string keyboard = "abcdefghijklmnopqrstuvwxyz";
  string word = "cba";

  cout << obj->calculateTime(keyboard, word) << endl;

  return 0;
}
