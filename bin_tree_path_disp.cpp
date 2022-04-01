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
  vector<string> allPaths;

  void getAllPaths(TreeNode *root, string currentPath)
  {
    if (root == NULL)
      return;

    currentPath += to_string(root->val);

    if (root->left == NULL and root->right == NULL)
    {
      allPaths.push_back(currentPath);
      return;
    }
    currentPath += "->";

    getAllPaths(root->left, currentPath);
    getAllPaths(root->right, currentPath);
    return;
  }

  vector<string> binaryTreePaths(TreeNode *root)
  {
    string currentPath = "";
    getAllPaths(root, currentPath);
    return allPaths;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *root = new TreeNode(1);
  /*
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->right = new TreeNode(5);
  */

  vector<string> data = obj->binaryTreePaths(root);

  for (string x : data)
  {
    cout << x << endl;
  }

  return 0;
}
