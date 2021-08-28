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
    vector<string> char_log;
    vector<string> num_log;

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
        num_log.push_back(logs[i]);
      }
      else
      {
        cout << buf << " "
             << " char " << endl;
        char_log.push_back(logs[i]);
      }
    }

    copy(begin(char_log), end(char_log), back_inserter(num_log));

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
