class Solution {
public:
    
    void dfs(int num,int n,int k,vector<int>&res)
    {
        if(n==0)
        {
            res.push_back(num);
            return;
        }
        
        int last_digit=num%10;
        
        if(last_digit >= k)
        {
            dfs(num*10 + last_digit - k,n-1,k,res);
        }
        if(last_digit + k < 10 and k > 0)
        {
            dfs(num*10+last_digit + k,n-1,k,res);
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        
        vector<int>res;
        
        if(N==1)
        {
            res.push_back(0);
        }
        
        for(int d=1;d<10;d++)
        {
            dfs(d,N-1,K,res);
        }
    return res;
    }
};