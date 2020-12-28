/*The idea is to observe that, a bit in the result of bitwise OR will be set if it is set in either of the operands. So, to maximize the value of the Bitwise OR:
We will sort the array in decreasing order.
Now, take the max element of the array as the maximum value of OR initially.
Now, traverse the array and for each element calculate its Bitwise OR with maxOR so far. If it is greater than maxOR so far then increment count.*/
#include<bits/stdc++.h>
using namespace std;

bool comp(int a,int b)
{
	return a>b;
}

int find_max_or(vector<int>&arr)
{
	sort(arr.begin(),arr.end(),comp);
	int max_or=arr[0];

	int count=1;

	for(int i=1;i<arr.size();i++)
	{
		if((max_or | arr[i]) >  max_or)
		{
			// if bitwise or with the next element is 

        // greater than current value 
			max_or=max_or|arr[i];
			count++;
		}
	}
	return count;
}


int main()
{
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<find_max_or(arr)<<"\n";
	return 0;
}