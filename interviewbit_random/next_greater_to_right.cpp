vector<int> Solution::nextGreater(vector<int> &arr) {
    
    vector<int>right(arr.size());
    right[arr.size()-1]=-1;
    
    stack<int>st;
    st.push(arr[arr.size()-1]);
    
    for(int i=arr.size()-2;i>=0;i--)
    {
        if(st.empty())
        {
            right[i]=-1;
        }
        else if(st.top() <= arr[i])
        {
            while(!st.empty() and st.top() <= arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                right[i]=-1;
            }
            else
            {
                right[i]=st.top();
            }
        }
        else if(st.top() > arr[i])
        {
            right[i]=st.top();
        }
        st.push(arr[i]);
    }
    return right;
}
