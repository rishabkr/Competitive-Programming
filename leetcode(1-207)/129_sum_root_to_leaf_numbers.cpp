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
    int sum;
    void solve(TreeNode* node,int curr_sum)
    {
        if(!node)
        {
            return;
        }
        
        curr_sum= curr_sum*10 + node->val;
        
        if(!node->left and !node->right)
        {
            sum+=curr_sum;
            return;
        }
        
        solve(node->left,curr_sum);
        solve(node->right,curr_sum);
    }
    
    int sumNumbers(TreeNode* root) {
        sum=0;
        int curr_sum=0;
        solve(root,curr_sum);
        
        return sum;
    }
};