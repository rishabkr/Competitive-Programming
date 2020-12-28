class Solution {
public:    
    int trap(vector<int>& heights) {
        int sz=heights.size();
        if(!sz)
        {
            return 0;
        }
        vector<int>left(sz,0);
        vector<int>right(sz,0);
        int sum=0;

        left[0]=heights[0];
        right[sz-1]=heights[sz-1];
        
        for(int i=1;i<sz;i++)
        {
            left[i]=max(left[i-1],heights[i]);
        }
        for(int i=sz-2;i>-1;i--)
        {
            right[i]=max(right[i+1],heights[i]);
        }
        for(int i=0;i<sz;i++)
        {
            sum+=min(left[i],right[i])-heights[i];
        }
        return sum;
    }
};