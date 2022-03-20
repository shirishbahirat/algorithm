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
  bool status = True;

  bool transverse(TreeNode *x, TreeNode *y)
  {
    if ((x == nullptr) && (y == nullptr))
    {
      return status == False ? False : True;
    }
    if ((x == nullptr) || (y == nullptr))
    {
      return False;
    }

    if (x->val == y->val)
    {
      return status == False ? False : True;
    }

    transverse(x->left, y->left);
    transverse(x->right, y->right);
  }

  bool isSameTree(TreeNode *p, TreeNode *q) { return true; }
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

  return 0;
}
