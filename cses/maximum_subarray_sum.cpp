#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	ll arr[n-1];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll current=arr[0];
	ll best=arr[0];
	for(int i=1;i<n;i++)
	{
		current=max(arr[i],arr[i]+current);
		if(current>best)
		{
			best=current;
		}
	}
cout<<best<<"\n";
return 0;
}