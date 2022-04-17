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
  void transverse(TreeNode *root, int &left, int &right)
  {

    if (root == nullptr)
      return;
  }

  bool isBalanced(TreeNode *root)
  {
    int l = 0, r = 0;

    transverse(root, l, r);

    return true;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *root = new TreeNode(5);

  root->left = new TreeNode(6);
  root->right = new TreeNode(8);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(7);

  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(9);

  obj->isBalanced(root);
  return 0;
}
