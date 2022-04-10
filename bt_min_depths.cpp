#include <iostream>
#include <queue>
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
  int empty = false;

  int transverse(TreeNode *root)
  {

    if (!root)
      return 0;

    if (root->left == nullptr && root->right == nullptr)
      return 1;

    int l = INT_MAX, r = INT_MAX;

    if (root->left)
      l = transverse(root->left);

    if (root->right)
      r = transverse(root->right);

    return (min(l, r) + 1);
  }

  int minDepth(TreeNode *root)
  {

    return transverse(root);
    ;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *root = new TreeNode(4);

  root->left = new TreeNode(2);
  root->right = new TreeNode(9);

  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(5);

  root->right->right = new TreeNode(7);

  cout << obj->minDepth(root) << endl;

  return 0;
}
