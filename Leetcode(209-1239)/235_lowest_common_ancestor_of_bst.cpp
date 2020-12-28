/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
        {
            return nullptr;
        }
   
        if(root->val>p->val and root->val > q->val)
        {
            return lca(root->left,p,q);
        }
        else if(root->val < p->val and root->val < q->val)
        {
            return lca(root->right,p,q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
        {
            return nullptr;
        }
        return lca(root,p,q);
        
    }
};