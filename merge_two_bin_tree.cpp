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

  void transverse(TreeNode *root1, TreeNode *root2, TreeNode *root)
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

    if (root1 == nullptr)
    {
      transverse(nullptr, root2->left, root->left);
      transverse(nullptr, root2->right, root->right);
    }
    else if (root2 == nullptr)
    {
      transverse(root1->left, nullptr, root->left);
      transverse(root1->right, nullptr, root->right);
    }
    else
    {
      transverse(root1->left, root2->left, root->left);
      transverse(root1->right, root2->right, root->right);
    }

    return;
  }

  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
  {

    transverse(root1, root2, root);

    return root;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *p = new TreeNode(1);
  TreeNode *q = new TreeNode(1);

  p->left = new TreeNode(1);
  p->right = new TreeNode(1);

  p->left->left = new TreeNode(1);
  p->left->right = new TreeNode(1);

  p->right->left = new TreeNode(2);
  p->right->right = new TreeNode(1);

  q->left = new TreeNode(1);
  q->right = new TreeNode(1);

  q->left->left = new TreeNode(1);
  q->left->right = new TreeNode(1);

  q->right->left = new TreeNode(2);
  q->right->right = new TreeNode(1);

  obj->mergeTrees(p, q);
  ;

  return 0;
}
