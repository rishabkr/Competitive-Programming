/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 bool is_valid(TreeNode* node,long long int min,long long int max)
 {
     if(!node)
     {
         return true;
     }
     if(node->val <= min or node->val >= max)
     {
         return false;
     }
 
     return is_valid(node->left,min,node->val) and is_valid(node->right,node->val,max);
 }
 
 
int Solution::isValidBST(TreeNode* A) {
    if(!A)
    {
        return true;
    }
    return is_valid(A,LONG_MIN,LONG_MAX);
}
