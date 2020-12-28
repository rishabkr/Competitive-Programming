/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 bool find_path(TreeNode* node,int target,vector<int>&path)
 {
     if(!node)
     {
         return false;
     }
     path.push_back(node->val);
     if(target==node->val or find_path(node->left,target,path) or find_path(node->right,target,path))
     {
         return true;
     }
     path.pop_back();
     return false;
 }
 
int Solution::lca(TreeNode* root, int p, int q) {
    
    vector<int>p_path;
    vector<int>q_path;
    
    bool p_exists=find_path(root,p,p_path);
    bool q_exists=find_path(root,q,q_path);
    
    if(!p_exists or !q_exists)
    {
        return -1;
    }
    
    int i=0;
    while(p_path[i]==q_path[i] and i<p_path.size() and i < q_path.size())
    {
        i++;
    }
    return p_path[i-1];
}
