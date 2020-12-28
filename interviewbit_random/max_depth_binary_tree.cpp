/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int max_depth(TreeNode* node)
 {
     if(!node)
     {
         return 0;
     }
     
     int max_left=max_depth(node->left);
     int max_right=max_depth(node->right);
     
     return 1+max(max_left,max_right);
 }
 
int Solution::maxDepth(TreeNode* A) {
    return max_depth(A);
}
