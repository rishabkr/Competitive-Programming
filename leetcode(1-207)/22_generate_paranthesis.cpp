class Solution {
public:
    
    //keep generating "(" till open<n and keep generating ")" till close<open 
    void generate_all(string curr,int open,int close,int n,vector<string>&res)
    {
        if(curr.length()==2*n)
        {
            res.push_back(curr);
            return;
        }
        
        if(open < n)
        {
            generate_all(curr+"(",open+1,close,n,res);
        }
        
        if(close<open)
        {
            generate_all(curr+")",open,close+1,n,res);
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        if(n==0)
        {
            return {};
        }
        vector<string>res;
        generate_all("(",1,0,n,res);
        return res;
    }
};