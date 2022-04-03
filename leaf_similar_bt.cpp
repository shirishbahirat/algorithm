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
  bool leafSimilar(TreeNode *root1, TreeNode *root2) { return true; }
};

root1 = [ 3, 5, 1, 6, 2, 9, 8, null, null, 7, 4 ] root2 =
    [3, 5, 1, 6, 7, 4, 2, null, null, null, null, null, null, 9, 8]

    int
    main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *root1 = new TreeNode(3);

  root1->left = new TreeNode(5);
  root1->right = new TreeNode(1);

  root1->left->left = new TreeNode(6);
  root1->left->right = new TreeNode(2);

  root1->right->left = new TreeNode(9);
  root1->right->right = new TreeNode(8);

  root1->left->right->left = new TreeNode(7);
  root1->left->right->right = new TreeNode(4);

  return 0;
}
