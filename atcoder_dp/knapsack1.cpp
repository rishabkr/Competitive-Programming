#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int W;
	cin>>W;
	vector<int>w(n);
	vector<ll>p(n);
	for(int i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		w[i]=a;
		p[i]=b;
	}
cout<<endl;
ll c[n+1][W+1];

for(int i=0;i<=n;i++)
{
	for(int curr_cap=0;curr_cap<=W;curr_cap++)
	{
		if(i==0||curr_cap==0)
		{
			c[i][curr_cap]=0;
		}
		else if(w[i-1]<=curr_cap)
		{
			//max among if we take the value or if we dont take the value
			c[i][curr_cap]=max(p[i-1]+c[i-1][curr_cap-w[i-1]],c[i-1][curr_cap]);
		}
		else
		{
			c[i][curr_cap]=c[i-1][curr_cap];
		}
	}
}
cout<<c[n][W]<<"\n";
	return 0;
}