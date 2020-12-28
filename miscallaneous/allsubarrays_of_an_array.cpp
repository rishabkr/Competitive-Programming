#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&max_arrs)
{
	cout<<"\n";
	for(auto i: max_arrs)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}

vector<int> divisors(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {   int n=arr[i];
        int prod=1;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                if(n/i==i)
                {
                   prod=prod*i; 
                }
                else
                {
                    prod=prod*i;
                    prod=prod*(n/i);
                }
            }
        }
        arr[i]=prod;
    }
    return arr;
}

int main()
{
	int n;
	cin>>n;

	vector<int>arr(n);
	vector<vector<int>>subarrs;

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	sort(arr.begin(),arr.end());
	int arr_size=(arr.size())*(arr.size()+1)/2;
	vector<int>max_arrs;
	unordered_map<int,int>mp;
	for(int i=0;i<arr.size();i++)
	{
		mp[arr[i]]=i+1;
	}
	for(auto it:mp)
	{
		for(int i=0;i<it.second;i++)
		{
			max_arrs.push_back(it.first);
		}
	}

	print(max_arrs);

	divisors(max_arrs);

	print(max_arrs);
return 0;
}