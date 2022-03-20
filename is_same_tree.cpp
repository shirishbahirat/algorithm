#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
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
