int Solution::evalRPN(vector<string> &str) {
    
    
    stack<int>st;
    
    for(string ch: str)
    {
        if(ch=="+")
        {
            int x2=st.top();
            st.pop();
            int x1=st.top();
            st.pop();
            
            st.push(x1+x2);
        }
        else if(ch=="-")
        {
            int x2=st.top();
            st.pop();
            int x1=st.top();
            st.pop();
            
            st.push(x1-x2);
        }
        else if(ch=="/")
        {
            int x2=st.top();
            st.pop();
            int x1=st.top();
            st.pop();
            
            st.push(x1/x2);
        }
        else if(ch=="*")
        {
            int x2=st.top();
            st.pop();
            int x1=st.top();
            st.pop();
            
            st.push(x1*x2);
        }
        else
        {
            st.push(stoi(ch));
        }
    }
    return st.top();
}
