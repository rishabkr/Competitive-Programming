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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head or !head->next)
        {
            return head;
        }
        ListNode *prev=NULL;
        ListNode* current=head;
        while(m>1)
        {
            prev=current;
            current=current->next;
            m--;
            n--;
        }
        
        ListNode* conn=prev;
        ListNode* tail=current;
        while(n-- > 0)
        {
            ListNode* next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        if(conn!=NULL)
        {
            conn->next=prev;
        }
        else
        {
            head=prev;
        }
        tail->next=current;
        return head;
    
}
};