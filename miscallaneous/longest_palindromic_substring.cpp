#include<bits/stdc++.h>
using namespace std;


void solve(string s)
{
    if(s.length() <= 1)
    {
        cout<<s<<"\n";
        return;
    }
    
    int max_length=1;
    int start=0;
    int end=0;
    int n=s.length();
    
    for(int i=0;i<n;i++)
    {
        int left=i;int right=i;
        
        while(left >=0 and right < n)
        {
            if(s[left] == s[right])
            {
                left--;right++;
            }
            else
            {
                break;
            }
        }
        
        if(right-left-1 > max_length)
        {
            max_length=right-left-1;
            start=left+1;   end=right-1;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        int left=i;int right=i+1;
        
        while(left >=0 and right < n)
        {
            if(s[left] == s[right])
            {
                left--;right++;
            }
            else
            {
                break;
            }
        }
        
        if(right-left-1 > max_length)
        {
            max_length=right-left-1;
            start=left+1;   end=right-1;
        }
    }
    
    cout<<s.substr(start,end-start+1)<<"\n";
    return;
}


int main()
 {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     int t;
     cin>>t;
     
     while(t--)
     {
         string s;
         cin>>s;
         solve(s);
     }
	return 0;
}