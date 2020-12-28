/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode* Solution::deleteDuplicates(ListNode* A) {
ListNode* curr = A;
ListNode* prev = nullptr;
ListNode* res = nullptr;

while(curr){
    if(curr->next && curr->val == curr->next->val){
        ListNode* cpy = curr;
        
        while(cpy->next && cpy->val == cpy->next->val){
            
            cpy = cpy->next;
        }
        if(prev) prev->next = cpy->next;
        curr = cpy->next;
    }
    else{
        if(!res) res = curr;
        prev = curr;
        curr = curr->next;
    }
}
return res;
}
}
