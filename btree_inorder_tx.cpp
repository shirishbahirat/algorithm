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
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> tree;

    inorder(root, tree);

    for (int k : tree)
    {
      cout << k << " ";
    }
    cout << endl;

    return tree;
  }

  void inorder(TreeNode *root, vector<int> &tree)
  {
    if (root == nullptr)
      return;

    inorder(root->left, tree);

    cout << root->val << endl;
    tree.push_back(root->val);

    inorder(root->right, tree);
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *head = new TreeNode(10);

  head->left = new TreeNode(8);
  head->right = new TreeNode(14);

  head->left->left = new TreeNode(6);
  head->left->right = new TreeNode(9);

  head->right->left = new TreeNode(12);
  head->right->right = new TreeNode(18);

  obj->inorderTraversal(head);

  return 0;
}
