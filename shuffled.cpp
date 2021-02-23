#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string restoreString(string s, vector<int> &indices)
  {
    string aux = s;

    for (int i = 0; i < indices.size(); ++i)
    {
      aux[indices.at(i)] = s[i];
    }
    return aux;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  string s = "codeleet";
  vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};

  string aux = obj->restoreString(s, indices);

  cout << aux << endl;

  return 0;
}
