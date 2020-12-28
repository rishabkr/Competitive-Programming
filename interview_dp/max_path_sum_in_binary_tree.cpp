/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int res;

int max_path_sum(TreeNode* node)
{

    if(!node)
    {
    return 0;
    }
    
    int left=max_path_sum(node->left);
    int right=max_path_sum(node->right);
    
    int temp=max(max(left,right)+node->val,node->val);
    int ans=max(temp,left+right+node->val);
    
    res=max(res,ans);
    return temp;
}
 
int Solution::maxPathSum(TreeNode* A) {
    res=INT_MIN;
    max_path_sum(A);
    return res;
}
