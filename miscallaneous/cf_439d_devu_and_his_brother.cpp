#include<bits/stdc++.h>
using namespace std;

int main()
{

int n,m;
cin>>n>>m;
vector<int>a(n);
vector<int>b(m);
vector<int>c(2*(m+n));



for(int i=0;i<n;i++)
{
	cin>>a[i];
	c[i]=a[i];
}

for(int j=0;j<m;j++)
{
	cin>>b[j];
	c[j+n]=b[j];
}

sort(c.begin(),c.begin()+n+m);
int mid=c[m];

long long ans=0;

for(int i=0;i<n;i++)
{
	ans+=max(0,mid-a[i]);
}

for(int i=0;i<m;i++)
{
	ans+=max(0,b[i]-mid);
}

cout<<ans;
return 0;
}