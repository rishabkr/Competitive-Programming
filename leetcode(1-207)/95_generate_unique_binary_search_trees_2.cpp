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
    
    vector<TreeNode*>generate_bst(int start,int end)
    {
        vector<TreeNode*>tree;
        
        if(start>end)
        {
            tree.push_back(NULL);
            return tree;
        }
        
        for(int i=start; i<=end; i++)
        {
            vector<TreeNode*>left=generate_bst(start,i-1);
            vector<TreeNode*>right=generate_bst(i+1,end);
            
            for(auto l: left)
            {
                for(auto r: right)
                {
                    auto root=new TreeNode();
                    root->val=i;
                    root->left=l;
                    root->right=r;
                    tree.push_back(root);
                }
            }
            
        }
        return tree;
    }
    
    
    
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
        {
            return {};
        }
        vector<TreeNode*>trees;
        return generate_bst(1,n);
    }
};