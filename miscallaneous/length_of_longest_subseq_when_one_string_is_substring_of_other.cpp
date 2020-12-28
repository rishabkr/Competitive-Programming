#include<bits/stdc++.h>
using namespace std;

void solve(string a,string b)
{
    int n=a.length();
    int m=b.length();
    
    vector<vector<int>>dp(1000,vector<int>(1000,0));
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j-1]==b[i-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        ans=max(ans,dp[i][n]);
    }
    cout<<ans<<"\n";
}

int main()
 {
     int t;
     cin>>t;
     
     while(t--)
     {
         int n,m;
         cin>>n>>m;
         string x,y;
         cin>>x>>y;
         solve(x,y);
     }
}