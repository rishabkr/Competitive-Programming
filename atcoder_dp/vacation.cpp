//https://atcoder.jp/contests/dp/tasks/dp_c
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<vector<int>>arr;
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		int a,b,c;
		cin>>a>>b>>c;
		temp.push_back(a);
		temp.push_back(b);
		temp.push_back(c);
		arr.push_back(temp);
	}
	vector<int>dp(3,0);
	dp[0]=arr[0][0];
	dp[1]=arr[0][1];
	dp[2]=arr[0][2];
	for(int i=1;i<n;i++)
	{
		vector<int>m(3,0);
		m[0]=max(arr[i][0]+dp[1],arr[i][0]+dp[2]);
		m[1]=max(arr[i][1]+dp[0],arr[i][1]+dp[2]);
		m[2]=max(arr[i][2]+dp[0],arr[i][2]+dp[1]);
		dp=m;		
	}
	cout<<*max_element(dp.begin(),dp.end());
	return 0;
}