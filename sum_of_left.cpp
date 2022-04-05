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
  int sum = 0;

  void transverse(TreeNode *root, bool left)
  {
    if (root == nullptr)
      return;

    if ((left) and (root->left == nullptr) and (root->right == nullptr))
    {
      sum += root->val;
    }

    transverse(root->left, true);
    transverse(root->right, false);

    return;
  }

  int sumOfLeftLeaves(TreeNode *root)
  {

    transverse(root, false);

    return sum;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
