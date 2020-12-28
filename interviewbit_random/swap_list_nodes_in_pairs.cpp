/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode* reverse(ListNode* head,int k)
 {
     ListNode* curr=head;
     for(int i=0;i<k;i++)
     {
         if(!curr)
         {
             return head;
         }
        curr=curr->next;
     }
     
     
     ListNode* current=head;
     ListNode* next=NULL;
     ListNode* prev=NULL;
     int m=0;
     
     while(current and m<k )
     {
         next=current->next;
         current->next=prev;
         prev=current;
         current=next;
         m++;
     }
     if(next)
     {
         head->next=reverse(next,k);
     }
     return prev;
 }
 
ListNode* Solution::swapPairs(ListNode* node) {
    if(!node or !node->next)
    {
        return node;
    }
    
   return reverse(node,2);
}
