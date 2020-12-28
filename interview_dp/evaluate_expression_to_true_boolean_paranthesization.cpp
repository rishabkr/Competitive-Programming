#define mod 1003
unordered_map<string,int>mp;

int solve(string s,int i,int j,char is_true)
{
    if(i > j) //string is empty
    {
        return 0;
    }
    
    if(i==j)
    {
        if(is_true == 'T')
        {
            return s[i]=='T';
        }
        else
        {
            return s[i]=='F';
        }
    }
    
    string temp="";
    temp+=to_string(i)+" "+ to_string(j)+ " ";
    temp.push_back(is_true);
    
    if(mp.count(temp)==1)
    {
        return mp[temp];
    }
    
    //cout<<temp<<"\n";
    int ans=0;
    for(int k=i+1; k<=j-1; k+=2)
    {
        int lt=solve(s,i,k-1,'T');
        int lf=solve(s,i,k-1,'F');
        int rt=solve(s,k+1,j,'T');
        int rf=solve(s,k+1,j,'F');
        
        if(s[k]=='&')
        {
            if(is_true=='T')
            {
                ans=ans + lt*rt;
            }
            else
            {
                ans=ans + lf*rt + lt*rf + lf*rf;
            }
        }
        else if(s[k]=='|')
        {
            if(is_true=='T')
            {
                ans= ans + lf*rt + lt*rt + lt*rf;
            }
            else
            {
                ans=ans+lf*rf;
            }
        }
        else if(s[k]=='^')
        {
            if(is_true=='T')
            {
                ans= ans+ lf*rt +lt*rf;
            }
            else
            {
                ans= ans + lt*rt + lf*rf;
            }
        }
    }
    
 mp[temp]=ans%mod;
    return ans%mod;
}

int Solution::cnttrue(string s) {
mp.clear();
return solve(s,0,s.length()-1,'T')%mod;

}
