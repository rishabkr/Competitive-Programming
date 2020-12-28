/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode* convert_to_bst(int start,int end,const vector<int>&A)
 {
     if(start > end)
     {
         return NULL;
     }
     
     int mid=start+ (end-start)/2;
     
     
     TreeNode* new_node=new TreeNode(A[mid]);
     
     new_node->left=convert_to_bst(start,mid-1,A);
     new_node->right=convert_to_bst(mid+1,end,A);
 
     return new_node;
 }
 
 
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    
   return convert_to_bst(0,A.size()-1,A);
}
