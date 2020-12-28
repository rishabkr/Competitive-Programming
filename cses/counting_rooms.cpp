#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int x[8]={-1,1,0,0};
int y[8]={0,0,-1,1};
void dfs(int i,int j,vector<vector<char>> &rooms,vector<vector<bool>>&visited)
{
if(i>rooms.size()-1||i<0||j<0||j>rooms[0].size()-1||visited[i][j]||rooms[i][j]=='#')
{
	return;
}
visited[i][j]=true;
for(int k=0;k<4;k++)
{
	dfs(i+x[k],j+y[k],rooms,visited);
}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n,m;
	cin>>n>>m;
	vector<vector<char>>rooms(n,vector<char>(m,'\0'));
	vector<vector<bool>>visited(n,vector<bool>(m,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>rooms[i][j];
		}
	}
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!visited[i][j]&&rooms[i][j]=='.')
			{	count+=1;
				dfs(i,j,rooms,visited);
			}
		}
	}
	cout<<count<<"\n";
	return 0;
 
}