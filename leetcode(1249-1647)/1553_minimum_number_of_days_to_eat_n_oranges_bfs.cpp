class Solution {
public:

    
    int solve(int n)
    {
        
        if(n==0 or n==1)
        {
            return n;
        }
        unordered_map<int,int>mp;
        
        queue<int>q;
        q.push(n);
        
        int n_minus_1=INT_MAX;
        int nby2=INT_MAX;
        int n2by3=INT_MAX;
        int count=0;
        while(!q.empty())
        {
            count+=1;
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                int front=q.front();
                q.pop();
                
                n_minus_1=front-1;
                q.push(n_minus_1);
                
                if(front%2==0 and mp.count(front/2)==0)
                {
                    nby2=front/2;
                    mp[nby2]+=1;
                    q.push(nby2);
                }
                if(front%3==0 and mp.count(front/3)==0)
                {
                    
                    n2by3=front/3;//front-front*2/3
                    mp[n2by3]+=1;
                    q.push(n2by3);
                }
                if(n_minus_1==0 or nby2==0 or n2by3==0)
                {
                    return count;
                }
                
            }
            
            
        }
        
        return count;
    }
    
    
    int minDays(int n) {
        return solve(n);
        
    }
};
