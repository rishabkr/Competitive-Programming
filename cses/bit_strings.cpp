#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long int ll;
#define EXP 1000000007
ll mod(ll x)
{
	return x%EXP;
}
ll bin_pow(ll a,ll b)
{
	if(b==0)
	{
		return 1;
	}
	if(b==1)
	{
		return a;
	}
else 
{
	ll res=bin_pow(a,b/2);
	res=mod(res*res);
	if(b&1)
	{
		res=mod(res*a);
	}
return res;
}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	cout<<bin_pow(2,n)<<"\n";
}