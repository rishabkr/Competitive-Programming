bool find_path(Node* node,int item,vector<Node*>&path)
{
    if(!node)
    {
        return false;
    }
    path.push_back(node);
    
    if(node->data==item or find_path(node->left,item,path) or find_path(node->right,item,path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

Node* find_lca(Node* root ,int a ,int b )
{   
    
    vector<Node*>path_a;
    vector<Node*>path_b;

    find_path(root,a,path_a);
    find_path(root,b,path_b);
    
    int i=0;
    while(i<min(path_a.size(),path_b.size()) and path_a[i]==path_b[i])
    {
        i++;
    }
    return path_a[i-1];
  
}
   
  
  int find_distance(Node *root,int x)
  {
    
    if(!root)
    {
        return -1;
    }
    
    int dist = -1; 
    if ((root->data == x) || (dist = find_distance(root->left, x)) >= 0 || (dist = find_distance(root->right, x)) >= 0) 
        return dist + 1; 
 
    return dist; 
  }
  
  
int findDist(Node* root, int a, int b) {
   Node* lca=find_lca(root,a,b);
   
   int distance_a=find_distance(lca,a);
   int distance_b=find_distance(lca,b);
   
   return distance_a+distance_b;
}