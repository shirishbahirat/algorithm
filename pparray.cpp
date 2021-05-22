#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  int *pmx = &matrix[0][0];

  int **ppmx = &pmx;

  void print(void)
  {

    for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
        cout << matrix[i][j] << " ";
      }

      cout << endl;
    }

    return;
  }

  void pprint(void)
  {

    for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
        cout << *pmx << " ";
        pmx++;
      }

      cout << endl;
    }

    return;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  obj->print();
  cout << " " << endl;
  obj->pprint();
  return 0;
}
