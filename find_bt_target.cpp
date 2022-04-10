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
  int element;

  bool found = false;

  void find(TreeNode *root, int element)
  {

    if (!root)
      return;

    if (element > root->val)
      find(root->right, element);
    else if (element < root->val)
      find(root->left, element);
    else
      found = true;
  }

  bool findTarget(TreeNode *root, int k)
  {

    if (!root)
      return false;

    element = k - root->val;

    if (!element)
      return true;

    find(root, element);

    return found;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
