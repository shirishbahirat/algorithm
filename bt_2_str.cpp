#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
 public:
  string tree2str(TreeNode* t) {
    return dfs(t);
  }

 private:
  string dfs(TreeNode* root) {
    if (!root)
      return "";

    const string& rootStr = to_string(root->val);
    if (root->right)
      return rootStr + "(" + dfs(root->left) + ")(" + dfs(root->right) + ")";
    if (root->left)
      return rootStr + "(" + dfs(root->left) + ")";
    return rootStr + "";
  }
};

int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    cout << obj->tree2str(root) << endl;

    return 0;
  }
