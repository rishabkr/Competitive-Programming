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
    int get_sum(TreeNode* node,int sum)
    {
       if(!node)
       {
           return 0;
       }
        
        sum=(sum<<1) + node->val;
        if(!node->left and !node->right)
        {
            return sum;
        }
        
        return get_sum(node->left,sum)+get_sum(node->right,sum);
       
    }
    
    int sumRootToLeaf(TreeNode* root) {
       
      return  get_sum(root,0);
        
    }
};


// class Solution {
// public:
//     int sum=0;
    
//     void get_sum(TreeNode* node,int count)
//     {
        
//         if(!node)
//         {
//             return;
//         }
        
//         if(!node->left and !node->right)
//         {
//             sum+=count*2+node->val;
//         }
        
//         count=count*2+node->val;
        
//         get_sum(node->left,count);
//         get_sum(node->right,count);
    
//     }
    
//     int sumRootToLeaf(TreeNode* root) {
//         sum=0;
        
//         get_sum(root,0);
        
//         return sum;
//     }
// };