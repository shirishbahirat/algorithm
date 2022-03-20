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
  bool status = true;

  bool transverse(TreeNode *x, TreeNode *y)
  {
    if ((x == nullptr) && (y == nullptr))
    {
      return status = (status ? true : false);
    }

    if ((x == nullptr) || (y == nullptr))
    {
      return (status = false);
    }

    if (x->val == y->val)
    {
      status = (status ? true : false);
      status = transverse(x->left, y->left);
      status = transverse(x->right, y->right);
    }
    else
    {
      return (status = false);
    }

    return status;
  }

  bool isSameTree(TreeNode *p, TreeNode *q) { return transverse(p, q); }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *p = new TreeNode(10);

  p->left = new TreeNode(8);
  p->right = new TreeNode(14);

  p->left->left = new TreeNode(6);
  p->left->right = new TreeNode(9);

  p->right->left = new TreeNode(12);
  p->right->right = new TreeNode(18);

  TreeNode *q = new TreeNode(10);

  q->left = new TreeNode(8);
  q->right = new TreeNode(14);

  q->left->left = new TreeNode(6);
  q->left->right = new TreeNode(9);

  q->right->left = new TreeNode(12);
  q->right->right = new TreeNode(18);

  bool stat = obj->isSameTree(p, q);

  cout << stat << endl;

  return 0;
}
