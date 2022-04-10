#include <iostream>
#include <queue>
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
  int left = 0;
  int right = 0;
  int empty = false;

  void transverse(TreeNode *root)
  {

    if (!root)
      return;

    queue<TreeNode *> ordered;

    ordered.push(root);

    while (!ordered.empty())
    {
      TreeNode *rt = ordered.front();
      cout << rt->val << endl;
      ordered.pop();

      if (rt->left != nullptr)
      {
        left++;
        ordered.push(rt->left);
      }

      if (rt->right != nullptr)
      {
        right++ ordered.push(rt->right);
      }
    }

    return;
  }

  int minDepth(TreeNode *root)
  {

    transverse(root);

    return min(left, right) + 1;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *root = new TreeNode(4);

  root->left = new TreeNode(2);
  root->right = new TreeNode(9);

  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(5);

  root->right->right = new TreeNode(7);

  cout << obj->minDepth(root) << endl;

  return 0;
}
