#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string defangIPaddr(string address)
  {

    string defang = "";

    for (int i = 0; i < address.size(); ++i)
    {
      if (address[i] == '.')
      {
        defang += "[.]";
      }
      else
      {
        defang += address[i];
      }
    }

    return defang;
  }
};

int main(int argc, char const *argv[])
{

  Solution *obj = new Solution();
  string address = "10.10.10.10";

  address = obj->defangIPaddr(address);

  cout << address << endl;
  return 0;
}