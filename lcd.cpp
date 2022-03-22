#include <iostream>

using namespace std;

struct node
{
  int val;
  node *left;
  node *right;
  node(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {

    if (root == nullptr)
      return NULL;

    if (root->val == p->val || root->val == q->val)
      return root;

    TreeNode *left_lca = lowestCommonAncestor(root->left, p, q);
    TreeNode *right_lca = lowestCommonAncestor(root->right, p, q);

    if (left_lca == NULL && right_lca == NULL)
      return NULL;
    if (left_lca != NULL && right_lca != NULL)
      return root;

    return (left_lca != NULL) ? left_lca : right_lca;
  }
};

void insert(node **hd, int val)
{
  if ((*hd) == nullptr)
  {
    (*hd) = new node(val);
    return;
  }

  if (val <= (*hd)->val)
  {
    insert(&(*hd)->left, val);
  }
  else
  {
    insert(&(*hd)->right, val);
  }
}

int main(int argc, char *argv[])
{

  node *root = nullptr;

  insert(&root, 5);
  insert(&root, 10);
  insert(&root, 4);
  insert(&root, 6);

  cout << root->val << endl;
  cout << root->left->val << endl;
  cout << root->right->val << endl;

  return 0;
}