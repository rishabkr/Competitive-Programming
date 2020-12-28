class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     
        if(k > nums.size())
        {
            return {*max_element(nums.begin(),nums.end())};
        }
        
        if(k == 0)
        {
            return {};
        }
        
        
        
        int i=0;
        int j=0;
        vector<int>res;
        deque<int>lst;
        
        while( j < nums.size())
        {
            while(lst.size() > 0 and lst.back() < nums[j])
            {
                lst.pop_back();
            }
            
            lst.push_back(nums[j]);
            
            if( j - i + 1 < k)
            {
                j++;
            }
            else if(j - i + 1 == k)
            {
                res.push_back(lst.front());
                
                if(lst.front() == nums[i])
                {
                    lst.pop_front();
                }
                
                i++;j++;
            }
        }
        return res;
    }
};