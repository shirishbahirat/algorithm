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
  int tilt = 0;

  int findTilt(TreeNode *root)
  {

    if (root == nullptr)
      return;

    int l, r;
    if (root->left == nullptr)
    {
      l = 0
    }
    else
    {
      l = root->left
    }

    if (root->right == nullptr)
    {
      r = 0;
    }
    else
    {
      r = root->right;
    }

    tilt += (l - r);

    findTilt(root->left);
    findTilt(root->right);

    return tilt;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *root = TreeNode(4);

  root->left = TreeNode(2);
  root->right = TreeNode(9);

  root->left->left = TreeNode(3);
  root->left->right = TreeNode(5);

  root->right->right = TreeNode(7);

  return 0;
}
