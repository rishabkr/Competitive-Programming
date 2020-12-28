/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool is_valid(TreeNode* root,long long int min,long long max)
    {
        if(!root)
        {
            return true;
        }
        if(root->val <= min or root->val >= max)
        {
            return false;
        }
       return is_valid(root->left,min,root->val) and is_valid(root->right,root->val,max);
    }
    
    
    bool isValidBST(TreeNode* root) {
        if(!root)
        {  
            return true;
        }
        
        return is_valid(root,LONG_MIN,LONG_MAX);
        
    }
};