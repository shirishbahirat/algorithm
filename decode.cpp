#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> decode(vector<int> &encoded, int first)
  {
    vector<int> decoded;

    decoded.push_back(first);
    int idx = 0;

    for (int i = 0; i < encoded.size(); ++i)
    {
      int data = decoded.at(idx) ^ encoded.at(i);
      decoded.push_back(data);
      idx++;
    }

    return decoded;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> encoded = {1, 2, 3};

  vector<int> decoded = obj->decode(encoded, 1);

  for (int i = 0; i < decoded.size(); ++i)
  {
    cout << decoded.at(i) << " ";
  }
  cout << endl;

  return 0;
}
