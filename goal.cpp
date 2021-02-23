#include <iostream>
using namespace std;

class Solution
{
public:
  string interpret(string command)
  {

    string parsed;

    for (int i = 0; i < command.size(); ++i)
    {
      if ((command[i] == '(') && (command[i + 1] == ')'))
      {
        parsed += 'o';
        ++i;
      }
      else if ((command[i] == '(') && (command[i + 1] == 'a'))
      {
        parsed += 'a';
        ++i;
      }
      else if ((command[i] == 'l') && (command[i + 1] == ')'))
      {
        parsed += 'l';
        ++i;
      }
      else
      {
        parsed += command[i];
      }
    }

    return parsed;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  string command = "G()(al)";
  string parsed = obj->interpret(command);
  cout << parsed << endl;
  return 0;
}
