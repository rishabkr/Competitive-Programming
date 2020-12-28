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
	int sum=0;
	for(int i=0;i<n-1;i++)
	{	
		int x;
		cin>>x;
		sum+=x;
	}
	int ans=0;
	ll total=(ll(n)*(n+1))/2;
	ans=total-sum;
	cout<<ans<<"\n";
	return 0;
}