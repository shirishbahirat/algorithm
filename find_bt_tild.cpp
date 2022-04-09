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
  int tilt = 0;

  int transverse(TreeNode *root, int *tilt)
  {

    if (!root)
      return 0;

    int left = transverse(root->left, tilt);
    int right = transverse(root->right, tilt);

    *tilt += abs(left - right);

    return left + right + root->val;
  }

  int findTilt(TreeNode *root)
  {

    transverse(root, &tilt);

    return tilt;
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

  cout << obj->findTilt(root) << endl;

  return 0;
}
