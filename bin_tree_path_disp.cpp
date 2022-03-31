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
  vector<string> data;

  void transverse(TreeNode *root)
  {
    if (root == nullptr)
      return;

    cout << root->val << "->";
    transverse(root->left);
    transverse(root->right);

    if ((root->left == nullptr) && (root->right == nullptr))
      cout << endl;
  }

  vector<string> binaryTreePaths(TreeNode *root)
  {

    transverse(root);

    return data;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *root = new TreeNode(1);

  root->left = new TreeNode(0);
  root->right = new TreeNode(1);

  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(1);

  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(1);

  obj->binaryTreePaths(root);

  return 0;
}
