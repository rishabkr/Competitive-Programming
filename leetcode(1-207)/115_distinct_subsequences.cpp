class Solution {
public:
  
    int iter(string &s, string &t){
        int i, j, m, n;
        m = s.size();
        n = t.size();
        vector<vector<long>> dp(s.size()+1, vector<long>(t.size()+1, 0));
        
        for(i = m; i >= 0; i--){
            dp[i][0] = 1;
        }
        
        for(i = 1; i <= m; i++){
            for(j = 1; j <= n; j++){
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i][j] + dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
    
    int numDistinct(string s, string t) {
        return iter(s, t);
    }
};