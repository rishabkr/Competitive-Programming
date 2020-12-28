#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(string str)
{
    unordered_map<char,int>mp;
    for(char ch: str)
    {
        mp[ch]++;
    }
    int distinct_characters_count=mp.size();
    
    
    int start=0;
    int start_index=-1;
    int min_length=INT_MAX;
    
    int window_count[256]={0};
    int current_count=0;
    int n=str.length();
    
    for(int i=0;i<n;i++)
    {
        window_count[str[i]]++;
        
        if(window_count[str[i]]==1)
        {
            current_count++;
        }
        
        if(current_count == distinct_characters_count)
        {
            
            while(window_count[str[start]] > 1)
            {
                if(window_count[str[start]] > 1)
                {
                    window_count[str[start]]--;
                }
                start++;
                
            }
            
            int current_length=i-start+1;
            
            if(current_length < min_length)
            {
                min_length=current_length;
                start_index=start;
            }
        }
        
    }
    
    //for finding  the substring str.substr(start_index,min_length);
    cout<<min_length<<"\n";
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
    string str;
    cin>>str;
    solve(str);
}

     
}