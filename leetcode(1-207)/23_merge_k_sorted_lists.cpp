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
    
    ListNode* merge2lists(ListNode* list1,ListNode* list2)
    {
     ListNode* result=nullptr;
        if(!list1)
        {
            return list2;
        }
        if(!list2)
        {
            return list1;
        }
        if(list1->val<=list2->val)
        {
            result=list1;
            result->next=merge2lists(list1->next,list2);
        }
        else
        {
            result=list2;
            result->next=merge2lists(list1,list2->next);
        }
        return result;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())
        {
            return NULL;
        }
        int last=lists.size()-1;
        while(last)
        {
            int start=0;
            int end=last;
            while(start<end)
            {
                lists[start]=merge2lists(lists[start],lists[end]);
                start++;
                end--;
                if(start>=end)
                {
                    last=end;
                }
            }
        }
        return lists[0];
    }
};