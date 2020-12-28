class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_ar=INT_MIN;
        
        int left_ptr=0;
        int right_ptr=heights.size()-1;
        
        while(left_ptr < right_ptr)
        {
            int width=right_ptr - left_ptr ;
            
            if(heights[left_ptr] < heights[right_ptr])
            {
                max_ar=max(max_ar, heights[left_ptr] * (width));
                left_ptr++;
            }
            else
            {
                max_ar=max(max_ar,heights[right_ptr]* ( width));
                right_ptr--;
            }
            
        }
        return max_ar;
    }
};