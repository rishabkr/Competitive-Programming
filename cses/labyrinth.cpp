#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isvalid(int i,int j,int n,int m)
{
	return (i >= 0 && i < n && j >= 0 && j < m);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n,m;
	cin>>n>>m;
	vector<vector<char>>map(n,vector<char>(m,'\0'));
	vector<vector<bool>>visited(n,vector<bool>(m,0));
	int starti,startj,desti,destj;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char x;
			cin>>x;
			map[i][j]=x;
			if(x=='A')
			{
				starti=i;
				startj=j;
			}
			if(x=='B')
			{
				desti=i;
				destj=j;
			}
		}
	}

	queue<pair<int,int>>q;
	q.push(make_pair(starti,startj));
	vector<char> path;
	while(!q.empty())
	{
		pair<int,int> current=q.front();
		int i=current.first;
		int j=current.second;
		visited[i][j]=true;
		if(map[i][j]=='B')
		{
			break;
		}
		else
		{

			q.pop();
			if(isvalid(i-1,j,n,m)&&map[i-1][j]=='.'&&!visited[i-1][j])
			{
				path.push_back('U');
				q.push(make_pair(i-1,j));
			}
		    if(isvalid(i+1,j,n,m)&&map[i+1][j]=='.'&&!visited[i+1][j])
			{
				path.push_back('D');
				q.push(make_pair(i+1,j));
			}
			if(isvalid(i,j-1,n,m)&&map[i][j-1]=='.'&&!visited[i][j-1])
			{
				path.push_back('L');
				q.push(make_pair(i,j-1));
			}
			if(isvalid(i,j+1,n,m) && map[i][j+1]=='.'&&!visited[i][j+1])
			{
				path.push_back('R');
				q.push(make_pair(i,j+1));
			}

		}

	}
	cout<<path.size()<<'\n';
	for(int i=0;i<path.size();i++)
	{
		cout<<path[i]<<" ";
	}
	return 0;
}
