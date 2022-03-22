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
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    TreeNode *head = nullptr;
    return head;
  }

  void traversal(TreeNode *root)
  {

    if (root == nullptr)
      return;

    cout << root->val << endl;

    traversal(root->left);
    traversal(root->right);

    return;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *head = new TreeNode(0);

  head->left = new TreeNode(-3);
  head->right = new TreeNode(9);

  head->left->left = new TreeNode(-10);

  head->right->left = new TreeNode(5);

  obj->traversal(head);

  return 0;
}
