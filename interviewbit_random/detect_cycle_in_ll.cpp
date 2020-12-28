/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head) {

if(not head)
{
    return NULL;
}
    bool loop_exists=0;
    ListNode* fast;
    ListNode* slow;
    
    for(fast=head,slow=head; fast and slow and fast->next;)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            loop_exists=1;
            break;
        }
    }
    if(loop_exists)
    {
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    
    return NULL;
}
