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

    return;
  }

  int maxDepth(TreeNode *root) { return 0; }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *p = new TreeNode(3);

  p->left = new TreeNode(9);
  p->right = new TreeNode(20);

  return 0;
}
