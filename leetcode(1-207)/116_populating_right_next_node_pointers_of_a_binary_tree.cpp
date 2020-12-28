/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
        {
            return root;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node* last=q.front();
            q.pop();
            int sz=q.size();
            if(last->left)
            {
                q.push(last->left);
                q.push(last->right);
            }
            for(int i=0;i<sz;i++)
            {   
                Node* front=q.front();
                q.pop();
                last->next=front;
                last=front;
                if(front->left)
                {
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        return root;
    }
};