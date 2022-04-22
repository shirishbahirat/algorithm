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
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> v;
        conversion(root,v);
        if(v.size()==1){return -1;} 
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1]!=v[i])
            {
                return v[i];
            }
        }
        return -1;
    }
    void conversion(TreeNode* root,vector<int>& v)
    {
        if(root==NULL){return;}
        conversion(root->left,v);
        v.push_back(root->val);
        conversion(root->right,v);
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
