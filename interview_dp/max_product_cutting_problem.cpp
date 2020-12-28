//https://www.geeksforgeeks.org/maximum-product-cutting-dp-36/
#include<bits/stdc++.h>
using namespace std;

int maximum(int a,int b,int c)
{
	return max(a,max(b,c));
}

int max_product_cutting(int n,vector<int>&max_cuttings)
{
	if(max_cuttings[n]!=-1)
	{
		return max_cuttings[n];
	}

	int maxi=0;

	for(int i=1;i<n;i++)
	{
		maxi=maximum(maxi,i*(n-i),i*max_product_cutting(n-i,max_cuttings));
	}
	max_cuttings[n]=maxi;
	return maxi;
}


int main()
{
	int n;
	cin>>n;
	cout<<"\n";
	vector<int>max_cuttings(n+1,-1);
	max_cuttings[0]=0;
	max_cuttings[1]=0;
	max_cuttings[2]=1;
	cout<<max_product_cutting(n,max_cuttings)<<"\n";
}