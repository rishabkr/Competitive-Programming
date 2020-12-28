/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


TreeNode* build_tree(vector<int>&preorder,unordered_map<int,int>&mp,int &preorder_index,int inorder_start,int inorder_end)
{
    if(inorder_start > inorder_end)
    {
        return NULL;
    }
    TreeNode* root=new TreeNode(preorder[preorder_index++]);
    if(inorder_start==inorder_end)
    {
        return root;
    }
    root->left=build_tree(preorder,mp,preorder_index,inorder_start,mp[root->val]-1);
    root->right=build_tree(preorder,mp,preorder_index,mp[root->val]+1,inorder_end);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    
    unordered_map<int,int>mp;
    for(int i=0;i<inorder.size();i++)
    {
        mp[inorder[i]]=i;
    }
    
    int preorder_index=0;
    
    return build_tree(preorder,mp,preorder_index,0,inorder.size()-1);
   }