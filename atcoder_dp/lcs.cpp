#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string res="";
	string s,t;
	cin>>s>>t;
	int n=s.length();
	int m=t.length();
	vector<vector<int>>lcs(n+1,vector<int>(m+1,0));
	int len=0;
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			
			if(s[i-1]==t[j-1])
			{
				lcs[i][j]=lcs[i-1][j-1]+1;
				
			}
			else
			{
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
			}
		}
	}

	int i=n;
	int j=m;
	while(i>0 and j>0)
	{
		if(lcs[i][j]==lcs[i][j-1])
		{

			j-=1;
		}
		else if(lcs[i][j]==lcs[i-1][j])
		{
			i-=1;
		}
		else
		{
			res=s[i-1]+res;
			i-=1;
			j-=1;
		}
	}	
cout<<res<<endl;
	return 0;
}