class Solution {
public:
    int find_(int x,vector<int>&parent)
    {
        if(parent[x]==-1)
        {
            return x;
        }
        
        parent[x]=find_(parent[x],parent);
        return parent[x];
    }
    
    void union_(int x,int y,vector<int>&parent)
    {
        int xp=find_(x,parent);
        int yp=find_(y,parent);
        
        if(xp!=yp)
        {
            parent[yp]=xp;
        }
    }
    
    
    int largestComponentSize(vector<int>& A) {
        vector<int>parent(100001,-1);
        
        for(auto x: A)
        {   //i<=sqrt(x);
            for(int i=2;i*i<=(x);i++)
            {
                if(x%i==0)
                {
                    union_(i,x,parent);
                    union_(x,x/i,parent);
                }
            }
        }
        int count=0;
        unordered_map<int,int>mp;
        
        for(auto x:A)
        {
            int root_of_x=find_(x,parent);
            count=max(count,1+mp[root_of_x]);
            mp[root_of_x]+=1;
        }
        return count;
    }
};