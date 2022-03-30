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
  int maxDepth(TreeNode *root)
  {

    if (root == nullptr)
      return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    if (left > right)
      return left + 1;
    else
      return right + 1;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *p = new TreeNode(3);

  p->left = new TreeNode(9);
  p->right = new TreeNode(20);

  p->right->left = new TreeNode(15);
  p->right->right = new TreeNode(7);

  obj->maxDepth(p);

  return 0;
}
