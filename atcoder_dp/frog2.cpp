//https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin>>n>>k;
	vector<ll> h;
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		h.push_back(x);
	}
	vector<ll>cost(n,INT_MAX);
	cost[0]=0;
	for(int i=0;i<n;i++)
	{
		int j=0;
		ll min_cost=INT_MAX;
		for(j=i+1;j<=i+k;j++)
		{
			if(j<n)
			{
				cost[j]=min(cost[j],cost[i]+abs(h[i]-h[j]));
			}
		}
	}
	cout<<cost[cost.size()-1]<<"\n";	
	return 0;
}