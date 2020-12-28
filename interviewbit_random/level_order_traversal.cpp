/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* root) {

    vector<vector<int>>res;
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty())
    {
        int size=q.size();
        vector<int> temp;
        for(int i=0;i<size;i++)
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
        res.push_back(temp);
    }
    return res;
}
