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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>res;
        if(!root)
        {
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool level=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                temp.push_back(front->val);
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }
            if(level)
            {
                reverse(temp.begin(),temp.end());
            }
            level=!level;
            res.push_back(temp);
        }
        return res;
    }
};