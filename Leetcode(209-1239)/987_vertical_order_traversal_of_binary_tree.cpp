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

void vertical_order_traversal(TreeNode* node,map<int,map<int,set<int>>>&mp,int hd,int vd)
{
 if(!node)
 {
     return;
 }
    mp[hd][vd].emplace(node->val);
    vertical_order_traversal(node->left,mp,hd-1,vd+1);
    vertical_order_traversal(node->right,mp,hd+1,vd+1);
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>>res;
            if(!root)
                {
        return res;
                }
        map<int,map<int,set<int>>>mp;
        vertical_order_traversal(root,mp,0,0);
        for(auto it:mp)
        {
            vector<int>temp;
            for(auto it2:it.second)
            {
                for(auto it3:it2.second)
                {
                    temp.push_back(it3);
                }
            }
            res.push_back(temp);
        }
    return res;
}
};