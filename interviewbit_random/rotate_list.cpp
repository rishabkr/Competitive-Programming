ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode* head=A;
    ListNode* main = NULL;
    ListNode* temp =NULL;
    
    
    if(A->next==NULL )
        return A;
    int cnt =1;
    
    
    while(A->next!=NULL){
        cnt++;
        A=A->next;
        temp = A;
    }
    
    
    if(B%cnt==0 && B!=1)
        return head;
    B = B%(cnt);
    A = head;
    int i=0;
    
    
    while(A!=NULL && i<cnt-B-1){
        i++;
        A=A->next;
    }
    
    
    main = A->next;
    A->next =NULL;
    temp->next = head;
    
    
    return main;
}