class Solution {
public:
    
    void evaluate(stack<int>&st,char c)
        {
                if(c=='/')
           {
               int a=st.top();st.pop();
               int b=st.top();st.pop();
               st.push(b/a);
           }
          else if(c=='+')
           {
               int a=st.top();st.pop();
               int b=st.top();st.pop();
               st.push(b+a);
           }
          else if(c=='-')
           {
               int a=st.top();st.pop();
               int b=st.top();st.pop();
               st.push(b-a);
           }
           else if(c=='*')
           {
               int a=st.top();st.pop();
               int b=st.top();st.pop();
               st.push(b*a);
           }
    }
    
    
    int evalRPN(vector<string>& tokens) {
     stack<int> st;
        for(auto c:tokens)
        { 
            if(c!="/" and c!="+" and c!="-" and c!="*" )
            {
                st.push(stoi(c));
            }
            else
            {
                evaluate(st,c[0]);
            }
        }
        int final=st.top();
        st.pop();
        return final;
    }
};