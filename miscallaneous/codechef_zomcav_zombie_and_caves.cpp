#include<bits/stdc++.h>

using namespace std;

void print(vector<int>&arr)
{
	for(auto i :arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}


int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		int n;

		cin>>n;

		vector<int>radiation(n);
		vector<int>health(n);

		vector<int>final_radiations(n);

		vector<int> difference(n+1,0);

		int left_index=0;
		int right_index=0;

		for(int i=0;i<n;i++)
		{
			cin>>radiation[i];

		}


		for(int i=0;i<n;i++)
		{
			cin>>health[i];
		}

		print(difference);
		for(int i=0;i<n;i++)
		{

			left_index=max(0,i-radiation[i]);     //i-c[i]
			right_index=min(n-1,i+ radiation[i]); //i+c[i]

			//without difference array for(int i=left_index;i<=right_index;i++)

			//with difference array

			difference[left_index]++;
			difference[right_index+1]--;
		}

		print(difference);
		
		final_radiations[0]=difference[0];

		for(int i=1;i<n;i++)
		{	
				final_radiations[i]=final_radiations[i-1]+difference[i];
		}

		sort(final_radiations.begin(), final_radiations.end());
		sort(health.begin(),health.end());


		bool matches=true;//there exists caves where zombies can be sent and eliminated

		for(int i=0;i<n;i++)
		{
			if(final_radiations[i]!=health[i])
			{
				matches=false;
				break;
			}
		}

		if(matches)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}


	return 0;
}