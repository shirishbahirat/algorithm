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
  void transverse(TreeNode *root)
  {

    if (root == nullptr)
      return;

    transverse(root->left);
    transverse(root->right);

    TreeNode *temp;

    temp = root->left;

    root->left = root->right;
    root->right = temp;

    return;
  }

  TreeNode *invertTree(TreeNode *root)
  {

    transverse(root);

    return root;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *p = new TreeNode(1);
  TreeNode *r;

  p->left = new TreeNode(1);
  p->right = new TreeNode(1);

  p->left->left = new TreeNode(1);
  p->left->right = new TreeNode(1);

  p->right->left = new TreeNode(2);
  p->right->right = new TreeNode(1);

  r = obj->invertTree(p);

  return 0;
}
