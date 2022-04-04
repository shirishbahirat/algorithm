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

  void depth_first_search(TreeNode *head, vector<int> &leaf)
  {

    if (head == nullptr)
      return;

    if ((head->left == nullptr) && (head->right == nullptr))
    {
      leaf.push_back(head->val);
    }

    depth_first_search(head->left, leaf);
    depth_first_search(head->right, leaf);

    return;
  }

  bool leafSimilar(TreeNode *root1, TreeNode *root2)
  {
    bool status = false;

    depth_first_search(root1, leaf1);
    depth_first_search(root2, leaf2);

    return status;
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

  bool status = obj->leafSimilar(root1, root2);

  cout << status << endl;

  return 0;
}
