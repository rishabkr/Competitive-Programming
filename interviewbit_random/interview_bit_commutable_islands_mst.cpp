int find_parent(vector<int>&parent,int x)
{
    if(parent[x] == -1)
    {
        
        return x;
    }
    return find_parent(parent,parent[x]);
}

void union_(vector<int>&parent,int a,int b)
{
    int parent_a=find_parent(parent,a);
    
    int parent_b=find_parent(parent,b);
    
    parent[a]=parent_b;
    
}


int Solution::solve(int A, vector<vector<int> > &B) {
  
    auto lambda_comp=[](vector<int> a ,vector<int> b)
    {
        return a[2] < b[2];
    };

        
    sort(B.begin(),B.end(),lambda_comp);
    
    vector<int> parent(A+1,-1);
    int ans=0;
    
    for(int i=0; i< B.size() ; i++)
    {
        
        int parent_a=find_parent(parent,B[i][0]-1);
        int parent_b=find_parent(parent,B[i][1]-1);
        
        if(parent_a != parent_b)
        {
            union_(parent,parent_a,parent_b);
            ans+=B[i][2];
        }
        
    }
 
 return ans;   
}
