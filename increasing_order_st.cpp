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
  TreeNode *tree = nullptr;
  TreeNode *start = nullptr;

  TreeNode *increasingBST(TreeNode *root)
  {

    traversal(&root);

    return start;
  }

  void add_node(TreeNode **root)
  {

    if (tree == nullptr)
    {
      tree = new TreeNode((*root)->val);
      start = tree;
      return;
    }

    tree->right = new TreeNode((*root)->val);
    tree->left = nullptr;
    tree = tree->right;
  }

  void traversal(TreeNode **root)
  {

    if ((*root) == nullptr)
      return;

    traversal(&(*root)->left);
    cout << (*root)->val << endl;
    add_node(root);
    traversal(&(*root)->right);

    return;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *head = new TreeNode(5);

  head->left = new TreeNode(3);
  head->right = new TreeNode(6);

  head->left->left = new TreeNode(2);
  head->left->right = new TreeNode(4);

  head->left->left->left = new TreeNode(1);

  head->right->right = new TreeNode(8);

  head->right->right->left = new TreeNode(7);
  head->right->right->right = new TreeNode(9);

  obj->traversal(&head);

  return 0;
}
