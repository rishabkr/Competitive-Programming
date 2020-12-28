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
    
        ListNode* swap(ListNode* head)
        {
            ListNode* cursor=head;
            for(int i=0;i<2;i++)
            {
                if(!cursor)
                {
                    return head;
                }
                cursor=cursor->next;
            }
            
            ListNode* prev=NULL;
            ListNode* next=NULL;
            ListNode* current=head;
            int m=0;
            while(current and m++<2)
            {
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
            }
            if(next)
            {
                head->next=swap(next);
            }
            return prev;
        }
    
    ListNode* swapPairs(ListNode* head) {
        if(!head)return head;
        if(!head->next or !head)
        {
            return head;
        }
        return swap(head);
    }
};