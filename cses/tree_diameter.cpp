#include<bits/stdc++.h>
using namespace std;
#define INF 999999999
int x;

void dfs_util(int node,int count,bool visited[],int &maxcnt,list<int>*adj)
{
	visited[node]=1;
	count+=1;
	for(auto i=adj[node].begin();i!=adj[node].end();++i)
	{
		if(!visited[*i])
		{
			if(count>=maxcnt)
			{
				maxcnt=count;
				x=*i;
			}
		dfs_util(*i,count,visited,maxcnt,adj);
		}

	}

}

void dfs(int node,int n,list<int>*adj,int &maxcnt)
{
bool visited[n+1]={0};
int count=0;
dfs_util(node,count+1,visited,maxcnt,adj);
}

int diameter(list<int>*adj,int n)
{
	int maxcnt=INT_MIN;
	dfs(1,n,adj,maxcnt);
	dfs(x,n,adj,maxcnt);
	return maxcnt;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int n;
cin>>n;
if(n==1)
{
	cout<<0<<'\n';
	return 0;
}
list<int>* adj=new list<int>[n+1];
for(int i=0;i<n-1;i++)
{
	int a,b;
	cin>>a>>b;
	adj[a].push_back(b);
	adj[b].push_back(a);
}

cout<<diameter(adj,n)-1<<"\n";

}