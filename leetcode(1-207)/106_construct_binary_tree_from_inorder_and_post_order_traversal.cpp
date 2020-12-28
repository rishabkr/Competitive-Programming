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
    
    TreeNode* build_tree(vector<int>&inorder,int i1,int i2,vector<int>&postorder,int p1,int p2)
    {
        if(i1>=i2 or p1>=p2)
        {
            return NULL;
        }
        
        TreeNode* root=new TreeNode(postorder[p2-1]);
        
        auto it=find(inorder.begin()+i1,inorder.end()+i2,postorder[p2-1]);// can use map here instead of searching everytime
        
        int diff=it-(inorder.begin()+i1);
        
        root->left=build_tree(inorder,i1,i1+diff,postorder,p1,p1+diff);
        root->right=build_tree(inorder,i1+diff+1,i2,postorder,p1+diff,p2-1);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 or postorder.size()==0)
        {
            return NULL;
        }
        if(inorder.size()!=postorder.size())
        {
            return NULL;
        }
        
        return build_tree(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
};