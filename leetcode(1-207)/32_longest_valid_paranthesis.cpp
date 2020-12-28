class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        
        stack<char>char_stack;
        stack<int> index_stack;
        
        index_stack.push(-1);
        int max_len=0;
    
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                index_stack.push(i);
                char_stack.push('(');
            }
            else if(s[i]==')')
            {
                if(!char_stack.empty() and char_stack.top()=='(')
                {
                    char_stack.pop();
                    index_stack.pop();
                    max_len=max(max_len,i-index_stack.top());
                }
                else
                {
                    index_stack.push(i);
                }
                
            }
            
        }
        return max_len;
        
    }
};