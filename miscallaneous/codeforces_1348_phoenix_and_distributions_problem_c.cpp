#include<bits/stdc++.h>
using namespace std;


int main()
{

	ios::sync_with_stdio(0);

	cout.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		int n,k;
		cin>>n>>k;


		string str;
		cin>>str;

		sort(str.begin(),str.end());

		if(str[0]!=str[k-1])
		{
			cout<<str[k-1]<<"\n";
			continue;
		}
		cout<<str[0];
		if(str[k]!=str[n-1])//remaining n-k letters are not same append remaining letters to answer
		{
			
			for(int i=k;i<n;i++)
			{
				cout<<str[i];
			}

		}
		else
		{
			 //remaining letters are the same, so we distribute evenly
			int remaining=n-k+k-1;

			for (int i=0;i<(remaining)/k;i++)
			{
				cout<<str[n-1];
			}
		}

		cout<<"\n";
	}
}