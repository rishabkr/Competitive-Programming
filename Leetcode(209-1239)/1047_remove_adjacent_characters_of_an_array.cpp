class Solution {
public:
    string removeDuplicates(string str) {
        if(str=="")
        {
            return "";
        }
        stack<char>st;
        string new_str="";
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(str[i]);
            }
            else if(str[i]==st.top())
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
        while(!st.empty())
        {
            char c=st.top();
            st.pop();
            new_str.push_back(c);
        }
        reverse(new_str.begin(),new_str.end());
        return new_str;
    }
};