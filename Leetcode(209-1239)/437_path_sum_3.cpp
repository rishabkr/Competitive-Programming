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
    int count;
    
    void calculate_sum(TreeNode* node,int curr_sum,int target)
    {
     
        if(!node)
        {
            return;
        }
        if(curr_sum+node->val==target)
        {
            count++;
        }
        calculate_sum(node->left,curr_sum+node->val,target);
        calculate_sum(node->right,curr_sum+node->val,target);        
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root)
        {
            return 0;
        }
        
        calculate_sum(root,0,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return count;
    }
};