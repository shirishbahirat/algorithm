#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<string> reorderLogFiles(vector<string> &logs)
  {
    vector<string> output;

    for (int i = 0; i < input.size(); i++)
    {
      cout << input[i] << endl;

      stringstream ss(input[i]);
      string buf;

      ss >> buf;
      ss >> buf;

      cout << buf << endl;
    }

    return output;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<string> input = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6",
                          "let2 own kit dig", "let3 art zero"};

  obj->reorderLogFiles(&input);

  return 0;
}
