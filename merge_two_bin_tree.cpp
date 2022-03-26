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
  TreeNode *root;

  void transverse(TreeNode *root1, TreeNode *root2)
  {

    if ((root1 == nullptr) && (root2 == nullptr))
      return;

    int val = 0;

    if (root1 != nullptr)
    {
      val += root1->val;
    }

    if (root2 != nullptr)
    {
      val += root2->val;
    }

    root = new TreeNode(val);

    transverse(root1->left, root2->left);

    transverse(root1->right, root2->right);

    return;
  }

  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) { return root; }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
