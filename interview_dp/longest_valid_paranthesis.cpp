class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int>index_st;
        stack<char>char_st;
        
        index_st.push(-1);
        
        int max_len=0;
        
        for(int i=0 ; i<s.length(); i++)
        {
            if(s[i] == '(')
            {
                index_st.push(i);
                char_st.push('(');
            }
            else
            {
                if(!char_st.empty() and char_st.top() == '(')
                {
                    char_st.pop();
                    index_st.pop();
                    
                    max_len=max(max_len, i - index_st.top());
                }
                else
                {
                    index_st.push(i); //no pair found // a problematic indx
                }
            }
        }
        return max_len;
    }
};