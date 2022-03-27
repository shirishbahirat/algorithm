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

    cout << root->val << endl;

    transverse(root->left);
    transverse(root->right);

    return;
  }

  TreeNode *searchBST(TreeNode *root, int val) { return root; }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *p = new TreeNode(10);

  p->left = new TreeNode(5);
  p->right = new TreeNode(15);

  p->left->left = new TreeNode(3);
  p->left->right = new TreeNode(7);

  p->right->left = new TreeNode(13);
  p->right->right = new TreeNode(18);

  obj->transverse(p);

  return 0;
}
