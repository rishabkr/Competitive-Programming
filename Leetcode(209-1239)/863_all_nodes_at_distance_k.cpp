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
    
    void create_parent_mapping( unordered_map<TreeNode*,TreeNode*>&parent_mp,TreeNode* node,TreeNode* parent)
    {
        if(!node)
        {
            return;
        }
        
        parent_mp[node]=parent;
        
        create_parent_mapping(parent_mp,node->left,node);
        create_parent_mapping(parent_mp,node->right,node);
    }
    
    vector<int>result_arr(queue<TreeNode*>&q)
    {
        vector<int>res;
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_mp;
    
        create_parent_mapping(parent_mp,root,NULL);
        
        queue<TreeNode*> q;
        q.push(target);
        
        set<TreeNode*>visited;
        visited.insert(target);
        
        int current_level=0;
        
        while(!q.empty())
        {
            if(current_level == k)
            {
                return result_arr(q);
            }
            
            int q_size=q.size();
            
            for(int i=0;i<q_size;i++)
            {
                TreeNode* current=q.front(); q.pop();
                
                if(current->left and visited.find(current->left)==visited.end())
                {
                    visited.insert(current->left);
                    q.push(current->left);
                }
                
                if(current->right and visited.find(current->right)==visited.end())
                {
                    visited.insert(current->right);
                    q.push(current->right);
                }
                
                TreeNode* current_parent= parent_mp[current];
                if(current_parent and visited.find(current_parent)==visited.end())
                {
                    visited.insert(current_parent);
                    q.push(current_parent);
                }
        
            }
            
            current_level+=1;
        }
        return {};
    }
};