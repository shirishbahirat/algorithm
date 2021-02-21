#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maximumWealth(vector<vector<int>> &accounts)
  {

    int max_balance = 0;
    int balance = 0;

    for (int i = 0; i < accounts.size(); ++i)
    {
      balance = 0;
      vector<int> banks = accounts.at(i);

      for (int j = 0; j < banks.size(); ++j)
      {
        balance += banks.at(j);
      }

      if (balance > max_balance)
      {
        max_balance = balance;
      }
    }

    return max_balance;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  vector<vector<int>> accounts = {{1, 3, 4}, {4, 5, 6}};
  int max = 0;
  max = obj->maximumWealth(accounts);

  cout << max << endl;
  return 0;
}
