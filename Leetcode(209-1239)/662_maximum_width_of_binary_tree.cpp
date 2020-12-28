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
/*  //hs overflow in one case
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int res=1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int count=q.size();
            
            int start=q.front().second;
            
            int end=q.back().second;
            res=max(res,end-start+1);
            for(int i=0;i<count;i++)
            {
                pair<TreeNode*,int> p=q.front();
                q.pop();
                int index=p.second;
                if(p.first->left)
                {
                    q.push({p.first->left,2*index+1});
                }
                if(p.first->right)
                {
                    q.push({p.first->right,2*index+2});
                }
                
            }
        }
        
        return res;
    }
*/

//push indexes as 2*index +1 and 2*index+2 and calculate the max diff of the front index and back index of the queue on each level ..we use index-start index to prevent overflow
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int res=1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int count=q.size();
            
            int start=q.front().second;
            
            int end=q.back().second;
            res=max(res,end-start+1);
            for(int i=0;i<count;i++)
            {
                pair<TreeNode*,int> p=q.front();
                q.pop();
                int index=p.second-start;
                if(p.first->left)
                {
                    q.push({p.first->left,2*index+1});
                }
                if(p.first->right)
                {
                    q.push({p.first->right,2*index+2});
                }
                
            }
        }
        
        return res;
    }
};