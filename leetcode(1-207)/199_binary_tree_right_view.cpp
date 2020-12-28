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
    vector<int>res;
    int max_level=0;
    void rightside(TreeNode* node,int current_level)
    {
        if(node)
        {
        if(max_level < current_level)
        {
            max_level=current_level;
            res.push_back(node->val);
        }
        rightside(node->right,current_level+1);
        rightside(node->left,current_level+1);
        }
        else
        {
            return;
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        rightside(root,1);
        return res;
    }
};