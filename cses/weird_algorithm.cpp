#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	vector<ll> arr;
	arr.push_back(n);
	while(n!=1)
	{
		if(n&1)
		{
			n=n*3+1;
			arr.push_back(n);
		}
		else
		{
			n=n/2;
			arr.push_back(n);
		}
	}
	int sz=arr.size();
	for(int i=0;i<sz;i++)
	{
		cout<<arr[i]<<" ";
	}

}