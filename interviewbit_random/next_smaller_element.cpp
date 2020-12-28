vector<int> Solution::prevSmaller(vector<int> &arr) {
    
    vector<int>vec;
    stack<int>st;
    int n=arr.size();
    
    for(int i=0;i<n;i++)
    {
        if(st.size() == 0)
        {
            vec.push_back(-1);
        }
        else if( st.size()>0 and st.top() < arr[i])
        {
            vec.push_back(st.top());
        }
        else if(st.size() > 0 and st.top() >= arr[i])
        {
            while(st.size() > 0 and st.top() >= arr[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                vec.push_back(-1);
            }
            else
            {
                vec.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    return vec;
}
