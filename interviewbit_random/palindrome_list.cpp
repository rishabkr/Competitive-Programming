/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 int is_palindrome(ListNode* head)
 {
     queue<int>q;
     stack<int>st;
     ListNode* curr=head;
     while(curr!=NULL)
     {
         q.push(curr->val);
         st.push(curr->val);
         //cout<<curr->val<<" ";
         curr=curr->next;
     }
     
     int sz=st.size();
     while(!st.empty())
     {
         int x=q.front();
         q.pop();
         int y=st.top();
         st.pop();
        
         if(x==y)
         {
             continue;
         }
         else
         {
             return 0;
         }
     }
     return 1;
 }
 
int Solution::lPalin(ListNode* A) {
    return is_palindrome(A);
}
