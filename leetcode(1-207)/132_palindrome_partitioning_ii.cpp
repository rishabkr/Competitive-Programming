class Solution {
public:
    
    vector<vector<int>>dp;
    
    bool is_palindrome(string s,int i,int j)
    {
        if(i>=j)
        {
            return true;
        }
        while(i < j)
        {
            if(s[i++]!=s[j--])
            {
                return false;
            }
        }
        return true;
    }
    
    int palindrome_partition(string s,int i,int j)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(is_palindrome(s,i,j))
        {
            return 0;
        }
        
        int ans=INT_MAX;
        
        for(int k=i; k < j ;k++)
        {
            int left,right;
            //breaking down temp=1 + solve(s,i,k) + solve(s,k+1,j) 
            
            if(dp[i][k] != -1)
            {
                left=dp[i][k];
            }
            else
            {
                left=palindrome_partition(s,i,k);
                dp[i][k]=left;
            }
            
            if(dp[k+1][j] != -1)
            {
                right=dp[k+1][j];
            }
            else
            {
                right=palindrome_partition(s,k+1,j);
                dp[k+1][j]=right;
            }

            int temp=1+left+right;
            
            ans=min(ans,temp);
        }
        
        return dp[i][j]=ans;
    }
    
    int minCut(string s) {
        if(!s.length())
        {
            return 0;
        }
        
        //cout<<s.length();
        if(is_palindrome(s,0,s.length()-1))
        {
            return 0;
        }
        dp.assign(s.length()+1,vector<int>(s.length()+1,-1));
        
        return palindrome_partition(s,0,s.length()-1);
    }
};