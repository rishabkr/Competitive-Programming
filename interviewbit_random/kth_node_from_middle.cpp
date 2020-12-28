/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* head, int k) {
    
    ListNode* temp=head;
    int length=0;
    while(temp)
    {
        length++;
        temp=temp->next;
    }
    int middle=(length/2)+1;
    if(middle-k-1 < 0)
    {
        return -1;
    }
    ListNode* kth=head;
    temp=head;
    int x=middle-k-1;
    
    while(x--)
    {
        temp=temp->next;
    }
    return temp->val;
}
