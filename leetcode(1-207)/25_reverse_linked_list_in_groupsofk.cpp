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
    ListNode* reverse(ListNode* head,int k)
    {
         ListNode* cursor = head;
        for(int i = 0; i < k; i++){//checks for node groups less than size k
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        int m=0;
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(current and m<k)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
            m++;
        }
        if(next){
        head->next=reverse(next,k);
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or !head->next)
        {
            return head;
        }
        return reverse(head,k);
    }
};