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
    int res;
    
    int solve(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }
        
        int left=solve(node->left);
        int right=solve(node->right);
        
        int temp=max(max(left,right)+ node->val,node->val);//if both ST are -ve
        
        int ans=max(temp,left+right+node->val); //currans
        
        res=max(res,ans);
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        res=INT_MIN;
        solve(root);
        
        return res;
    }
};