/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
//  */

ListNode* Solution::deleteDuplicates(ListNode* head) {
    if(head->next==NULL)
    {
        return head;
    }

    ListNode* p1=head,*p2=p1->next;
    while(p1!=NULL)
    {
        while(p2!=NULL and p1->val==p2->val)
        {
            p2=p2->next;
        }
        
        p1->next=p2;
        p1=p2;
    }
    return head;
}
