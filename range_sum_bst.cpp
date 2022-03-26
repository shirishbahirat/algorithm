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
  int sum = 0;

  void transverse(TreeNode *root, int low, int high)
  {

    if (root == nullptr)
      return;

    transverse(root->left, low, high);

    if ((root->val >= low) && (root->val <= high))
    {
      sum += root->val
    }

    transverse(root->right, low, high);

    return;
  }

  int rangeSumBST(TreeNode *root, int low, int high)
  {

    transverse(root, low, high);

    return sum;
  }
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

  bool status = obj->rangeSumBST(p, 5, 15);

  cout << "out " << status << endl;

  return 0;
}
