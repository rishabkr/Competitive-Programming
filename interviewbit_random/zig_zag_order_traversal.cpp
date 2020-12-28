/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* node) {

vector<vector<int>>res;

queue<TreeNode*>q;
q.push(node);
int level=-1;
while(!q.empty())
{
    vector<int>temp;
    int size=q.size();
    level++;
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
    if(level%2==1)
    {
        reverse(temp.begin(),temp.end());
        res.push_back(temp);
    }
    else
    {
        res.push_back(temp);
    }
}

return res;

    
}
