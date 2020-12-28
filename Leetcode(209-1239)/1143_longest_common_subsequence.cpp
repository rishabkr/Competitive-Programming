class Solution {
public:
     int longest_common_subsequence(string a,string b)
    {
        
        int m=a.length();
        int n=b.length();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        return longest_common_subsequence(text1,text2);
    }
};