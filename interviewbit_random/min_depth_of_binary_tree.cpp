/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* root) {
    queue<TreeNode*>q;
    if(!root)
    {
        return 0;
    }
    int level=0;
    q.push(root);
    
    while(!q.empty())
    {
        int size=q.size();
        level++;
        for(int i=0;i<size;i++)
        {
            TreeNode* front=q.front();
            q.pop();
            if(not front->left and not front->right)
            {
                return level;
            }
            if(front->left)
            {
                q.push(front->left);
            }
            if(front->right)
            {
                q.push(front->right);
            }
        }
    }
    return level;
}
