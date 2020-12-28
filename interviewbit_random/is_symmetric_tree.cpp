/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
    bool is_mirror(TreeNode* node1, TreeNode* node2)
    {
        if(not node1 and not node2)
        {
            return true;
        }
        if((node1 and not node2) or (node2 and not node1))
        {
            return false;
        }
        if(node1->val != node2->val)
        {
            return false;
        }
        return node1->val==node2->val and is_mirror(node1->left,node2->right) and is_mirror(node1->right,node2->left);
    }
 
int Solution::isSymmetric(TreeNode* A) {
    
    return is_mirror(A,A);
}
