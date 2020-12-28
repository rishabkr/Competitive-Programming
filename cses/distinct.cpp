#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	map<ll,ll> hash;
	int n;
	cin>>n;
	ll count=0;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		if(hash[x]==0)
		{
			hash[x]++;
			count++;
		}
		else
		{
			hash[x]++;
		}
	}
cout<<count<<"\n";
}