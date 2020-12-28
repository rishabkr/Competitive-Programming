#include<bits/stdc++.h>
#define ERR 1e-9
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<double>p;
	for(int i=0;i<n;i++)
	{
		double x;
		cin>>x;
		p.push_back(x);
	}
    vector<vector<double>>dp(n+1,vector<double>(n+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
    	for(int j=0;j<=n;j++)
    	{
    		if(j==0)
    		{
    			dp[i][j]=(1-p[i-1])*dp[i-1][j];
    		}
    		else
    		{
    			dp[i][j]=((1-p[i-1])*dp[i-1][j])+(p[i-1]*dp[i-1][j-1]);
    		}
    	}
    }
    double prob_greater_than_n=0;
    int count=ceil(n/2);
    for(int i=count+1;i<=n;i++)
    {
    	prob_greater_than_n+=dp[n][i];
    }
    cout<<setprecision(9)<<prob_greater_than_n<<endl;
 	return 0;
}