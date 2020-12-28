
void solve(int open,int close,string op,vector<string>&res)
{
    if(open==0 and close==0)
    {
        res.push_back(op);
        return;
    }
    
    if(open!=0)
    {
        string op1=op;
        op1+='(';
        solve(open-1,close,op1,res);
    }
    if(close > open)
    {
        string op2=op;
        op2+=')';
        solve(open,close-1,op2,res);
    }
}

vector<string> Solution::generateParenthesis(int n) {
    int open=n;
    int close=n;
    string op="";
    vector<string>res;
    
    solve(open,close,op,res);
    return res;
    
}
