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
    
    bool is_mirror(TreeNode* node1, TreeNode* node2)
    {
        if(not node1 and not node2 )
        {
            return true;
        }
        if(!node1 or !node2)
        {
            return false;
        }
        
        if(node1->val != node2->val)
        {
            return false;
        }
        return node1->val==node2->val and is_mirror(node1->left,node2->right) and is_mirror(node1->right,node2->left);
        
    }
    
    bool isSymmetric(TreeNode* root) {
        return is_mirror(root,root);
    }
};