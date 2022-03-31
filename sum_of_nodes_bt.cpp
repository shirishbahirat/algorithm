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
  void getSum(TreeNode *root, int n)
  {
    if (!root)
      return;
    n = 2 * n + root->val;
    getSum(root->left, n);
    getSum(root->right, n);
    if (!root->left && !root->right)
    {
      sum += n;
    }
  }
  int sumRootToLeaf(TreeNode *root)
  {
    getSum(root, 0);
    return sum;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *root = new TreeNode(1);

  root->left = new TreeNode(0);
  root->right = new TreeNode(1);

  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(1);

  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(1);

  return 0;
}
