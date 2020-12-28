class Solution {
public:
    void clear(stack<int>&st)
    {
        while(!st.empty())
        {
            st.pop();
        }
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        if(!heights.size())
        {
            return 0;
        }
        int n=heights.size();
        
        vector<int>left(n);
        vector<int>right(n);
        vector<int>width(n);
        
        
        stack<int>st;
        //left
        for(int i=0;i<n;i++)
        {
            
            while(!st.empty() and heights[st.top()] >= heights[i])
            {
             st.pop();   
            }
            if(st.empty())
            {
               left[i]=-1;
            }
            else
            {
                left[i]=st.top();
            }
            st.push(i);
        }
        
        clear(st);
        
        for(int i=n-1;i>=0;i--)
        {
            
            while(!st.empty() and heights[st.top()] >= heights[i])
            {
             st.pop();   
            }
            if(st.empty())
            {
               right[i]=n;
            }
            else
            {
                right[i]=st.top();
            }
            st.push(i);
        }
        
        int area=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            width[i]=right[i]-left[i]-1;
            
            area=max(area,width[i]*heights[i]);
 
        }
        return area;
    }
};