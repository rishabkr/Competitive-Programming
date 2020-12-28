#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void print(vector<ll>arr)
{
	for(auto a: arr)
	{
		cout<<a<<" ";
	}
	cout<<"\n";
}


void print2(multiset<ll>mass)
{
	for(auto mas:mass)
	{
		cout<<mas<<" ";
	}
	cout<<"\n";
}

int main()
{
	ll n;
	ll a,b;
	cin>>n>>a>>b;

    vector<ll> prefix(n+1);
    prefix[0] = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        prefix[i] = prefix[i-1] + x;
    }
    // print(prefix);
	ll ans=-2e18;

	multiset<ll>current;

	for(ll i=a;i<=n;i++)
	{
		if(i > b)
		{
			current.erase(current.find(prefix[i-b-1]));
		}
        
       current.insert(prefix[i-a]);
      	
		ans=max(ans,prefix[i] - *current.begin());
	}

	cout<<ans<<"\n";

return 0;
}