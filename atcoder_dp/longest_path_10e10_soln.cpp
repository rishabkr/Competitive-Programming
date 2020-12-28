#include<bits/stdc++.h>
using namespace std;
int dfs(int i,vector<vector<int>>&g)
{
	int temp=0;
	for(auto adj:g[i])
	{
		temp=max(temp,dfs(adj,g)+1);
	}
	return temp;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int m;
	cin>>n>>m;
	vector<vector<int>>g(n);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		g[x].push_back(y);
	}
	int res=INT_MIN;
	for(int i =0;i<n;i++)
	{
		res=max(res,dfs(i,g));
	}
	cout<<res;
	return 0;
}