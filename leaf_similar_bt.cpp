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
  vector<int> leaf1;
  vector<int> leaf2;

  void transverse(TreeNode *root1, TreeNode *root2)
  {

    if ((root1 == nullptr) and (root2 == nullptr))
      return;

    if ((root1 != nullptr) and (root2 == nullptr))
    {
      cout << "root1 " << root1->val << endl;
      if ((root1->left->left == nullptr) && (root1->left->right == nullptr))
      {
        leaf1.push_back(root1->val);
      }

      if ((root1->right->left == nullptr) && (root1->right->right == nullptr))
      {
        leaf1.push_back(root1->val);
      }

      transverse(root1->left, nullptr);
      transverse(root1->right, nullptr);
    }
    else if ((root1 == nullptr) and (root2 != nullptr))
    {
      cout << "root2 " << root2->val << endl;

      if ((root2->left->left == nullptr) && (root2->left->right == nullptr))
      {
        leaf2.push_back(root2->val);
      }

      if ((root2->right->left == nullptr) && (root2->right->right == nullptr))
      {
        leaf2.push_back(root1->val);
      }

      transverse(nullptr, root2->left);
      transverse(nullptr, root2->right);
    }
    else
    {
      cout << "root1 " << root1->val << endl;
      cout << "root2 " << root2->val << endl;

      transverse(root1->left, root2->left);
      transverse(root1->right, root2->right);
    }

    return;
  }

  bool leafSimilar(TreeNode *root1, TreeNode *root2)
  {

    transverse(root1, root2);

    return true;
  }
};

// root1 = [ 3, 5, 1, 6, 2, 9, 8, null, null, 7, 4 ]
// root2 = [3, 5, 1, 6, 7, 4, 2, null, null, null, null, null, null, 9, 8]

int main(int argc, char const *argv[])
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

  TreeNode *root2 = new TreeNode(3);

  root2->left = new TreeNode(5);
  root2->right = new TreeNode(1);

  root2->left->left = new TreeNode(6);
  root2->left->right = new TreeNode(7);

  root2->right->left = new TreeNode(4);
  root2->right->right = new TreeNode(2);

  root2->right->right->left = new TreeNode(9);
  root2->right->right->right = new TreeNode(8);

  obj->leafSimilar(root1, root2);

  return 0;
}
