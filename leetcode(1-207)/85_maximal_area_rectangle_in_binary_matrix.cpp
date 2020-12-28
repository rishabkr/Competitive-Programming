class Solution {
public:
        
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
    void print(vector<int>arr)
    {
        for(auto i : arr)
        {
        cout<<i<<" ";
        }
        cout<<endl;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(!matrix.size())
        {
            return 0;
        }
        vector<int>v;
        int num_rows=matrix.size();
        int num_cols=matrix[0].size();
        
        for(int j=0;j<num_cols;j++)
        {
            if(matrix[0][j]=='1')
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
        }
        //idea is to convert 2d array to 1d array using cummulative height sum
        int max_ar=maximum_area_histogram(v);
        
        for(int i=1;i<num_rows;i++)
        {   
            //print(v);
            for(int j=0;j<num_cols;j++)
            {
                if(matrix[i][j]=='1')
                {
                    v[j]+=1;
                }
                else
                {
                    v[j]=0;
                }
            }
            int curr_ar=maximum_area_histogram(v);
            max_ar=max(max_ar,curr_ar);
        }
     
        return max_ar;
    }
};