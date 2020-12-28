class Solution {
public:
    
    void solve(string ip,string op,vector<string>&res)
    {
        if(ip.length()==0)
        {
            res.push_back(op);
            return;
        }
        if(isalpha(ip[0]))
        {
            string op1=op;
            string op2=op;
            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            
            ip.erase(ip.begin()+0);
            solve(ip,op1,res);
            solve(ip,op2,res);
        }        
        else
        {
            string op1=op;
            op1.push_back(ip[0]);
            ip.erase(ip.begin()+0);
            solve(ip,op1,res);
        }
        return;
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string>res;
        
        string op="";
        solve(S,op,res);
        return res;
    }
};