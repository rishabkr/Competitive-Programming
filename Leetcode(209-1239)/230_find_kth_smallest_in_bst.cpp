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
    int count=0;
    int result;
    void kth_element(TreeNode* node,int k)
    {
        if(node->left)
        {
            kth_element(node->left,k);
        }
            count+=1;
            if(count==k)
            {
                result= node->val;
                return;
            }
        if(node->right)
        {
            kth_element(node->right,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        count=0;
        result=0;
        
        kth_element(root,k);
        return result;
    }
};