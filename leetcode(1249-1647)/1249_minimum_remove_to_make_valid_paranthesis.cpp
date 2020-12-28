//with stack like longest valid paranthesis
class Solution {
public:
    string minRemoveToMakeValid(string s) {
     
        stack<char>char_st;
        stack<int>idx_st;
        
        for(int i=0 ;i <s.length() ; i++)
        {
            if(s[i] == '(')
            {
                char_st.push('(');
                idx_st.push(i);
            }
            else if(s[i]==')')
            {
                if(!char_st.empty() and char_st.top()== '(')
                {
                    char_st.pop();
                    idx_st.pop();
                }
                else
                {
                    idx_st.push(i);
                }
            }
        }
        
        vector<bool>problem(s.length(),0);
        while(!idx_st.empty())
        {
            problem[idx_st.top()]=1;
            idx_st.pop();
        }
        
        string res="";
        for(int i=0;i<s.length();i++)
        {
            if(not problem[i])
            {
                res.push_back(s[i]);
            }
        }
        return res;
        
    }
};

//without stack
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    string minRemoveToMakeValid(string s) {
        string str="";
        int open=0;
        for(char c:s)
        {
           if(c=='(')
           {
               open++;
           }
            else if(c==')')
            {
                if(open==0)//if we see closing befroe an opening
                    continue;
                open--;
            }
            str.push_back(c);
        }
        cout<<str<<endl;
        string res="";
        for(int i=str.length()-1;i>=0;i--)
        {
            if(str[i]=='(' and open-->0)
                continue;
            res.push_back(str[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};