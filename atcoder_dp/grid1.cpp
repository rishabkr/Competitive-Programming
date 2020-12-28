#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int mod(int a) 
{ 
    return (a%MOD + MOD) % MOD; 
} 
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int h,w;
	cin>>h>>w;
	vector<vector<char>>g(h,vector<char>(w));
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			char x; cin>>x; g[i][j]=x;
		}
	}
	vector<vector<int>>dp(h,vector<int>(w,0));
	dp[0][0]=1;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(g[i][j]=='#')
			{
				continue;
			}
			if(i>0)
			{
				dp[i][j]+=mod(dp[i-1][j]);
			}
			if(j>0)
			{
				dp[i][j]+=mod(dp[i][j-1]);
			}
		}
	}
	cout<<mod(dp[h-1][w-1]);
return 0;
}