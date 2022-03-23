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
  TreeNode *increasingBST(TreeNode *root) { return root; }

  void traversal(TreeNode *root)
  {

    if (root == nullptr)
      return;

    traversal(root->left);
    cout << root->val << endl;
    traversal(root->right);

    return;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *head = new TreeNode(5);

  head->left = new TreeNode(3);
  head->right = new TreeNode(6);

  head->left->left = new TreeNode(2);
  head->left->right = new TreeNode(4);

  head->left->left->left = new TreeNode(1);

  head->right->right = new TreeNode(8);

  head->right->right->left = new TreeNode(7);
  head->right->right->right = new TreeNode(9);

  return 0;
}
