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
    
    bool solve(TreeNode* node,int target)
    {
     if(!node)
     {
         return 0;
     }
    
    
    if(!node->left and !node->right)
    {
        if(target-node->val==0)
        {
            return 1;
        }
        return 0;
    }
        
    bool left=solve(node->left,target-node->val);
    bool right=solve(node->right,target-node->val);
        
    return left or right;
        
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        
        return solve(root,sum);
    }
};