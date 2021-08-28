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

    for (int i = 0; i < logs.size(); i++)
    {
      cout << logs[i] << endl;

      stringstream ss(logs[i]);
      string buf;

      ss >> buf;
      ss >> buf;

      if ((buf[0] > 47) && (buf[0] < 58))
      {
        cout << buf << " "
             << " num " << endl;
      }
      else
      {
        cout << buf << " "
             << " char " << endl;
      }
    }

    return output;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<string> input = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6",
                          "let2 own kit dig", "let3 art zero"};

  obj->reorderLogFiles(input);

  return 0;
}
