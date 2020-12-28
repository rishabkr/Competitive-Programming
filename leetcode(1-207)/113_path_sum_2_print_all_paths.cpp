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
    vector<vector<int>>all_paths;
    vector<int>path;
    
    bool is_leaf(TreeNode* node)
    {
        return !node->left and !node->right;
    }
    
    void get_path(TreeNode* node,int reqd_sum)
    {
        path.push_back(node->val);
        
        if(is_leaf(node) and reqd_sum==node->val)
        {
            all_paths.push_back(path);
        }
        if(node->left)
        {
            get_path(node->left,reqd_sum-node->val);
        }
        if(node->right)
        {
            get_path(node->right,reqd_sum-node->val);
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
        {
            return all_paths;
        }
        get_path(root,sum);
        return all_paths;
    }
};