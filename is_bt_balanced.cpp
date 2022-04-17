#include <iostream>
#include <stack>
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
  stack<TreeNode *> stack;

  void transverse(TreeNode *root)
  {

    if (root == nullptr)
      return;

    stack.push(root);

    while (!stack.empty())
    {
      TreeNode *node = stack.top();
      stack.pop();

      cout << node->val << endl;

      if (node->right != nullptr)
        stack.push(node->right);

      if (node->left != nullptr)
        stack.push(node->left);
    }
  }

  bool isBalanced(TreeNode *root)
  {

    transverse(root);

    return true;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *root = new TreeNode(5);

  root->left = new TreeNode(6);
  root->right = new TreeNode(8);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(7);

  obj->isBalanced(root);
  return 0;
}
