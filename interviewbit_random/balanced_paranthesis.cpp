int Solution::solve(string str) {
    stack<char>st;
    
    for(char ch : str)
    {
        if(ch=='(')
        {
            st.push(ch);
        }
        else if(ch==')')
        {
            if(st.empty())
            {
                return 0;
            }
            if(st.top()=='(')
            {
                st.pop();
            }
        }
    }
    return st.empty();
}
