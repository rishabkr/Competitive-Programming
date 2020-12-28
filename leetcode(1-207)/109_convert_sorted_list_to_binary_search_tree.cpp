/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* construct_tree_from_array(vector<int>&nums,int left,int right)
    {
        if(left > right)
        {
            return NULL;
        }
        int mid=left+(right-left)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=construct_tree_from_array(nums,left,mid-1);
        node->right=construct_tree_from_array(nums,mid+1,right);
        return node;
    }
    
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>list;
        auto temp= head;
        while(temp!=NULL)
        {
            list.push_back(temp->val);
            temp=temp->next;
        }
        if(!list.size())
        {
            return NULL;
        }
        return construct_tree_from_array(list,0,list.size()-1);
        
    }
};