class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        deque<TreeNode *> dq;
        dq.push_back(root);
        
        int level_no = 0;
        
        while (!dq.empty())
        {
            ++level_no;
            vector<int> level;
            if (level_no % 2 == 0) // No. of level is even
            {
                int n = dq.size();
                while (n-->0)
                {
                    TreeNode *node = dq.back();
                    dq.pop_back();
                    if (node)
                    {
                        level.push_back(node->val);
                        dq.push_front(node->right);
                        dq.push_front(node->left);
                    }
                }
            }
            else // No. of level is odd
            {
                int n = dq.size();
                while (n-->0)
                {
                    TreeNode *node = dq.front();
                    dq.pop_front();
                    if (node)
                    {
                        level.push_back(node->val);
                        dq.push_back(node->left);
                        dq.push_back(node->right);
                    }
                }
            }
            if (!level.empty()) res.push_back(std::move(level));
        }
        
        return res;
    }
};