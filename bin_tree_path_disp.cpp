#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right)
  {
  }
};

class Solution
{
public:
  vector<string> data;
  vector<string> binaryTreePaths(TreeNode *root) { return data; }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
