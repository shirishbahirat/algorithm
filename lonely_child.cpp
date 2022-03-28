#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> getLonelyNodes(TreeNode *root)
  {
    vector<int> nodes;

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

  vector<int> nodes = obj->getLonelyNodes(root);
  return 0;
}
