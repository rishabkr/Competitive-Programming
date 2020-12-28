/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

void set_random_nodes(Node* temp)
{
    while(temp)
    {
        (temp->next)->random =temp->random ? (temp->random)->next : NULL;
        temp=temp->next->next;
    }
}

void split_alternate_nodes(Node *current)
{
   Node *curr=current;
    Node* temp=current->next;
    while(curr and temp)
    {
        curr->next=temp->next;
        curr=curr->next;
        if(temp->next)
        {
            temp->next=temp->next->next;
            temp=temp->next;
        }
    }
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return head;
        }
    Node* current=new Node(head->val);
    Node * new_head=new Node(head->val);
    current=head;
        while(current)
    {
        Node *temp=new Node(current->val);
            temp->random=NULL;
            temp->next=current->next;
            current->next=temp;
            current=temp->next;
    }
    new_head=head->next;
    set_random_nodes(head);
    split_alternate_nodes(head);
    return new_head;    
    }
};