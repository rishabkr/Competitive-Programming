#include<bits/stdc++.h>
using namespace std;

int longest_bitonic_subsequence(vector<int>&arr)
{
    vector<int>lis(arr.size(),1);
    vector<int>lds(arr.size(),1);
    
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                lis[i]=max(lis[i],lis[j]+1);
            }
        }
    }
    
    for(int i=arr.size()-2;i>=0;i--)
    {
        for(int j=arr.size()-1;j>i;j--)
        {
            if(arr[i]>arr[j])
            {
            lds[i]=max(lds[i],lds[j]+1);
            }
        }
    }
    int res=lis[0]+lds[0]-1;
    for(int i=0;i<lis.size();i++)
    {
        res=max(res,lis[i]+lds[i]-1);
    }
    return res;
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
         vector<int>arr(n);
         for(int i=0;i<n;i++)
         {
             cin>>arr[i];
         }
         cout<<longest_bitonic_subsequence(arr)<<"\n";
     }
	return 0;
}