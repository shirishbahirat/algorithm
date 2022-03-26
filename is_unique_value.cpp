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
  bool result = true;
  int val;

  void init(TreeNode *root)
  {
    if (root != nullptr)
    {
      val = root->val;
    }
  }

  bool transverse(TreeNode *root)
  {

    if (root == nullptr)
      return false;

    transverse(root->left);
    transverse(root->right);
    cout << root->val << endl;

    if (val != root->val)
    {
      result = false;
    }

    return result;
  }

  bool isUnivalTree(TreeNode *root)
  {
    init(root);

    result = transverse(root);

    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *p = new TreeNode(1);

  p->left = new TreeNode(1);
  p->right = new TreeNode(1);

  p->left->left = new TreeNode(1);
  p->left->right = new TreeNode(1);

  p->right->left = new TreeNode(2);
  p->right->right = new TreeNode(1);

  bool status = obj->isUnivalTree(p);

  cout << "out " << status << endl;

  return 0;
}
