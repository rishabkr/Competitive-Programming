#include<bits/stdc++.h>
using namespace std;

long long int merge(vector<int>&arr,vector<int>&temp,int left,int mid,int right)
{
    int i=left;
    int j=mid;
    int k=left;
    long long int inversion_count=0;
    
    while(i<=mid-1 and j<=right)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            
            inversion_count+=(mid-i);//most imp line
        }
    }
    while(i<=mid-1)
    {
        temp[k++]=arr[i++];
    }
    while(j<=right)
    {
        temp[k++]=arr[j++];
    }
    
    for(i=left;i<=right;i++)
    {
        arr[i]=temp[i];
    }
    return inversion_count;
}



long long int merge_sort(vector<int>&arr,vector<int>&temp,int left,int right)
{
    long long int inversion_count=0;
    
    if(right>left)
    {
        int mid=left+(right-left)/2;
        
        inversion_count+=merge_sort(arr,temp,left,mid);
        inversion_count+=merge_sort(arr,temp,mid+1,right);
        
        inversion_count+=merge(arr,temp,left,mid+1,right);
    }
    return inversion_count;
}

void solve(vector<int>&arr)
{
   
    vector<int>temp(arr.size());
    cout<<merge_sort(arr,temp,0,arr.size()-1)<<"\n";
}

int main()
 {
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
         
         solve(arr);
     }   
     
 }