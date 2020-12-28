//https://atcoder.jp/contests/abc177/tasks/abc177_d

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>adj;
vector<bool>visited;


int dfs(int node)
{

	int size=0;
	if(!visited[node])
	{
	
		visited[node]=true;
		size++;
	}


	for(auto neighbour : adj[node])
	{
		if(!visited[neighbour])
		{
			size = size + dfs(neighbour);
		}
	}

	return size;
}



int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin>>n>>m;

	adj.resize(n+10);
	visited.assign(n+10,false);

	for(int i=0;i < m ;i++)
	{
		int a,b;
		cin>>a>>b;

		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);

	}


	int max_component_size=INT_MIN;

	for(int i=0 ;i < n ;i++)
	{
		int temp_size=0;
		if(!visited[i])
		{
			temp_size=dfs(i);
		}

		max_component_size=max(max_component_size,temp_size);
	}

	cout<<max_component_size;

return 0;
}