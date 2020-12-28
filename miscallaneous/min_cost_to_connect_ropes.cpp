#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(vector<ll>&arr)
{
    priority_queue<ll,vector<ll>,greater<ll>>minh;
    for(ll num : arr)
    {
        minh.push(num);
    }
    ll total_cost=0;
    while(minh.size()>=2)
    {
        ll first=minh.top();
        minh.pop();
        ll second=minh.top();
        minh.pop();
        total_cost+=(first+second);
        minh.push(first+second);
    }
    cout<<total_cost<<"\n";
}

int main()
 {
     ios::sync_with_stdio(0);
     cin.tie(0);
     
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr);
    }

}