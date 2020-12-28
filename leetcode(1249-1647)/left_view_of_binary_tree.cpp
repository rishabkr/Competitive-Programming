vector<int> leftView(Node *root)
{
   vector<int>res;
   if(!root)
   {
       return res;
   }
   queue<Node*>q;
   q.push(root);
   
   while(!q.empty())
   {
       int qsize=q.size();
       for(int i=0;i<qsize;i++)
       {
           Node* front=q.front();
           q.pop();
           
           if(i==0)
           {
               res.push_back(front->data);
           }
           
           if(front->left)
            q.push(front->left);
           if(front->right)
            q.push(front->right);
       }
   }
   return res;
}
