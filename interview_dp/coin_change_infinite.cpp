int Solution::coinchange2(vector<int> &coins, int sum) {
int mod=1000007;

//vector<vector<int>>dp(coins.size()+1,vector<int>(sum+1,0));

vector<int>first(sum+1,0);
first[0]=1;
vector<int>second=first;

for(int i=1;i<=coins.size();i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coins[i-1]<=j)
            {
                //dp[i][j]=(dp[i-1][j]+dp[i][j-coins[i-1]])%mod;
            
                second[j]=(first[j] + second[j - coins[i-1]])%mod;
            }
            else
            {
                //dp[i][j]=(dp[i-1][j])%mod;
                second[j]=first[j]%mod;
            }
        }
        first=second;
    }
    return second[sum]%mod;
}
