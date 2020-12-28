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
     
     if(node->val==target or find_path(node->left,target,path) or find_path(node->right,target,path))
     {
         return true;
     }
     path.pop_back();
     return false;
 }
 
 
vector<int> Solution::solve(TreeNode* root, int target) {
    vector<int>path;
    find_path(root,target,path);
    return path;
}
