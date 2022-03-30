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
  vector<int> nodes;

  void transverse(TreeNode *root)
  {
    if (root == nullptr)
      return;

    if ((root->left == nullptr) || (root->right == nullptr))
    {
      nodes.push_back(root->val);
    }

    transverse(root->left);
    transverse(root->right);

    return;
  }

  vector<int> getLonelyNodes(TreeNode *root)
  {

    transverse(root);

    return nodes;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *p = new TreeNode(1);

  p->left = new TreeNode(1);
  p->right = new TreeNode(1);

  p->left->left = new TreeNode(1);
  p->left->right = new TreeNode(1);

  p->right->left = new TreeNode(2);
  p->right->right = new TreeNode(1);

  vector<int> nodes = obj->getLonelyNodes(p);

  for (int i : nodes)
  {
    cout << i << endl;
  }

  return 0;
}
