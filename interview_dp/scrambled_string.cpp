
unordered_map<string,bool>mp;

bool solve(string a,string b)
{
    if(a.compare(b)==0)
    {
        return 1;
    }
    if(a.length() <= 1)
    {
        return 0;
    }
    
    string key=a + "_" + b;
    
    if(mp.find(key)!=mp.end())
    {
        return mp[key];
    }
    
    int n=a.length();
    bool flag=0;
    
    for(int i=1; i<=n-1; i++)
    {
        bool condition1=solve(a.substr(0,i),b.substr(n-i,i)) and solve(a.substr(i,n-i),b.substr(0,n-i));
        bool condition2=solve(a.substr(0,i),b.substr(0,i)) and solve(a.substr(i,n-i),b.substr(i,n-i));
        if(condition1 or condition2)
        {
            flag=1;
            break;
        }
    }
    return mp[key]=flag;
}

int Solution::isScramble(const string a, const string b) {
    mp.clear();
    if(a.length() != b.length())
    {
        return 0;
    }
    if(a=="" and b=="")
    {
        return 1;
    }
    string s1=a;
    string s2=b;
    return solve(a,b);
}
