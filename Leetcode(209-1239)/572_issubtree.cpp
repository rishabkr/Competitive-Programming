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
    
    bool equals(TreeNode* s,TreeNode* t)
    {
        if(!s and !t)return true;
        if(!s or !t)return false;
        return s->val==t->val and equals(s->left,t->left) and equals(s->right,t->right);
    }
    
    bool traverse(TreeNode* s ,TreeNode *t)
    {
        return (s and (equals(s,t) or traverse(s->left,t) or traverse(s->right,t)));
    }
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if(!s and !t)
        {
            return true;
        }
        if(!s or !t)
        {
            return false;
        }
        return traverse(s,t);
    }
};