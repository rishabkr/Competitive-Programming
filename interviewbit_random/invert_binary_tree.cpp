/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode* invert(TreeNode* tree)
 {
     if(!tree)
     {
         return NULL;
     }
        if(!tree->left and !tree->right)
        {
            return tree;
        }
        
     TreeNode* left=invert(tree->right);
     TreeNode* right=invert(tree->left);
     
     tree->left=left;
     tree->right=right;
     return tree;
 }
 

TreeNode* Solution::invertTree(TreeNode* A) {
    return invert(A);
}
