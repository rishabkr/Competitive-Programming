 void clear(stack<pair<int,int>>&st)
    {
        while(st.size() > 0)
        {
            st.pop();
        }
    }
    
    
    int maximum_area_histogram(vector<int>&heights)
    {
        stack<pair<int,int>>st;
        vector<int>left;
        vector<int>right;
        int n=heights.size();
        
        //find nearest small to left
        for(int i=0 ;i < n;i++)
        {
            if(st.empty())
            {
                left.push_back(-1); //pseudo_index_if no smaller element on left
            }
            else if(st.size() > 0 and st.top().first < heights[i])
            {
                left.push_back(st.top().second);
            }
            else if(st.size() > 0 and st.top().first >= heights[i] )
            {
                while(st.size() > 0 and st.top().first >= heights[i])
                {
                    st.pop();
                }
                
                if(st.size()==0)
                {
                    left.push_back(-1);
                }
                else
                {
                    left.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
        }
        clear(st);
        //now find nearest smaller element to the right
        for(int i=n-1 ;i >= 0;i--)
        {
            if(st.empty())
            {
                right.push_back(n); //pseudo_index_if no smaller element on left
            }
            else if(st.size() > 0 and st.top().first < heights[i])
            {
                right.push_back(st.top().second);
            }
            else if(st.size() > 0 and st.top().first >= heights[i] )
            {
                while(st.size() > 0 and st.top().first >= heights[i])
                {
                    st.pop();
                }
                
                if(st.size()==0)
                {
                    right.push_back(n);
                }
                else
                {
                    right.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
        }
        
        reverse(right.begin(),right.end());
        int max_ar=0;
        
        for(int i=0;i<n;i++)
        {
            int width=right[i]-left[i]-1;
            int height=heights[i];
            max_ar=max(max_ar,width*height);
        }
        return max_ar;
    }
    

int Solution::largestRectangleArea(vector<int> &A) {
     return maximum_area_histogram(A);
}
