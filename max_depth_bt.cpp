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
  int x = 0;
  int y = 0;

  void transverse(TreeNode *root, bool l, bool r)
  {

    if (root == nullptr)
      return;

    cout << root->val << " " << x << " " << y << endl;

    if (l)
      x += 1;

    if (r)
      y += 1;

    transverse(root->left, true, false);

    transverse(root->right, false, true);

    return;
  }

  int maxDepth(TreeNode *root)
  {

    transverse(root, false, false);

    cout << x << " " << y << endl;

    return 0;
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
