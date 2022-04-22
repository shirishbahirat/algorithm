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

    int min = INT_MAX;
    int secondmin = INT_MAX;
    int taken = 0;

    void transverse_min(TreeNode* root)
    {
        if(root == nullptr)
            return; 

        if (root->val < min)
        {
            min = root->val;
        }

        transverse_min(root->left);
        transverse_min(root->right);

    }

    void transverse_2min(TreeNode* root)
    {
        if(root == nullptr)
            return; 

        if (root->val < min)
        {
            min = root->val;
        }

        if ((root->val > min) && (root->val < secondmin))
        {
            secondmin = root->val;
            taken = 1;
        }

        transverse_2min(root->left);
        transverse_2min(root->right);

    }

    int findSecondMinimumValue(TreeNode* root) {

        TreeNode* temp = root;
        
        transverse_min(root);

        root = temp;

        transverse_2min(root);

        if (taken)
            return secondmin;
        else
            return -1;
    }
};

int main(int argc, char const *argv[])
{

    Solution *obj = new Solution();

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(8);

    cout << obj->findSecondMinimumValue(root) << endl;

    return 0;

}
