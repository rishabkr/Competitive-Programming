#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>arr;
	int xorr=0;
	int q;
	cin>>q;
	arr.push_back(0);
	while(q--)
	{
		int type,element;

		cin>>type>>element;

		if(type==0)
		{
			arr.push_back(element);
			arr.back()^=xorr;
		}
		else
		{
			xorr^=element;
		}

	}

	for(int i=0;i<arr.size();i++)
	{
		arr[i]^=xorr;
	}
	sort(arr.begin(),arr.end());
  	
  	for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<' ';


	return 0;
}