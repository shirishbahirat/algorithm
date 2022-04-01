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
  string val = "";

  void transverse(TreeNode *root)
  {
    if (root == nullptr)
      return;

    transverse(root->left);
    cout << root->val;
    val += to_string(root->val);

    if (root->right)
    {
      cout << "->";
      val += "->";
    }

    transverse(root->right);

    if ((root->left == nullptr) && (root->right == nullptr))
    {
      cout << endl;
      data.push_back(val);
    }
  }

  vector<string> binaryTreePaths(TreeNode *root)
  {
    cout << root->val << "->";
    transverse(root);

    return data;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *root = new TreeNode(1);

  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->right = new TreeNode(5);

  obj->binaryTreePaths(root);

  return 0;
}
