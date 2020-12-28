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
    vector<TreeNode*>p_path;
    vector<TreeNode*>q_path;
    
    bool get_ppath(TreeNode*root,TreeNode* p,vector<TreeNode*>&path)
    {
        if(!root)
        {
            return false;
        }
        path.push_back(root);
        
        if(root==p or get_ppath(root->left,p,path) or get_ppath(root->right,p,path))
        {
            return true;
        }
        path.pop_back();
        return false;
    }


    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        get_ppath(root,p,p_path);
        get_ppath(root,q,q_path);
        int i = 0;
        while (i < min(p_path.size(), q_path.size()) and p_path[i] == q_path[i]) {
            i += 1;
        }
        return p_path[i-1];
    }
};