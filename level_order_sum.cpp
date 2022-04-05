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
  vector<double> output;

  vector<double> sum;
  vector<double> index;

  void transverse(TreeNode *root, int level)
  {
    if (root == nullptr)
      return;

    cout << root->val << " " << level << endl;

    if (sum.size() <= level)
    {
      sum.push_back(0);
      index.push_back(0);
    }

    index[level] += 1;
    sum[level] += root->val;

    transverse(root->left, level + 1);

    transverse(root->right, level + 1);
  }

  vector<double> averageOfLevels(TreeNode *root)
  {
    transverse(root, 0);

    for (int i = 0; i < sum.size(); ++i)
    {
      if (index[i] > 0)
      {
        output.push_back(sum[i] / index[i]);
      }
    }

    return data;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  TreeNode *root = new TreeNode(3);

  root->left = new TreeNode(5);
  root->right = new TreeNode(1);

  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);

  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(8);

  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  obj->averageOfLevels(root);

  return 0;
}
