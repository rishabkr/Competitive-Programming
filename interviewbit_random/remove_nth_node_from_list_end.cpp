/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* head, int k) {
    
    ListNode* node=head;
    ListNode* temp=head;
    int size=0;
    while(temp!=NULL)
    {
        size++;
        temp=temp->next;
    }
    if(size <= k)
    {
       return head->next;
    }
    
    for(int i=0;i<k;i++)
    {
        node=node->next;
    }
    temp=head;
    ListNode* prev=NULL;
    while(node!=NULL)
    {
        prev=temp;
        temp=temp->next;
        node=node->next;
    }
    prev->next=temp->next;
    free(temp);
    return head;
}
