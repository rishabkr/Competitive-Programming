int Solution::solve(string str) {
    
    int brackets=0;
    int ans=0;
    
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            brackets++;
        }
        else
        {
            brackets--;
        }
        
        if(brackets < 0)
        {
            ans+=1;
            brackets=0;
        }
    }
    return ans+brackets;
}
