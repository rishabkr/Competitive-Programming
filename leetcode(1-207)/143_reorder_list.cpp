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
    void reorderList(ListNode* head) {
     
        stack<ListNode*>st;
        
        auto *curr=head;
        
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->next;
        }
        
        curr=head;
        int n=st.size();
        if(n <= 2)
        {
            return ;
        }
        
        ListNode* next;
        
        for(int i=0;i<n/2;i++)
        {
            next=curr->next;
            curr->next=st.top();
            st.pop();
            curr=curr->next;
            curr->next=next;
            curr=curr->next;
        }
        curr->next=NULL;
        
        
    }
};

/*
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
/*
class Solution {
public:
    void reorderList(ListNode* head) {
     
    if(!head or !head->next)
    {
        return;
    }
        
        auto *slow=head;
        auto *fast=head;
        
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* prev=NULL;
        auto *curr=slow;
        ListNode* next;
        
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        
        auto *n1=head;
        auto *n2=prev;
        
        while(n2->next)
        {
            next=n1->next;
            n1->next=n2;
            
            n1=next;
            
            next=n2->next;
            n2->next=n1;
            n2=next;
        }
    }
};
/*