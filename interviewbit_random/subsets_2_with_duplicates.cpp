void solve(vector<int>ip,vector<int>op,vector<vector<int>>&res,map<vector<int>,int>&mp)
{
    if(ip.size()==0)
    {
        sort(op.begin(),op.end());
        mp[op]+=1;
        if(mp[op]==1)
        {
            
            res.push_back(op);
        }
        return;
    }
    
    vector<int>op1=op;
    vector<int>op2=op;
    
    op2.push_back(ip[0]);
    
    ip.erase(ip.begin()+0);
    
    solve(ip,op1,res,mp);
    solve(ip,op2,res,mp);
}


vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    map<vector<int>,int>mp;
    vector<vector<int>>res;
    solve(A,{},res,mp);
    sort(res.begin(),res.end());
    return res;
    
}
