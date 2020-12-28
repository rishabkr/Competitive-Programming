
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size() < 2)
        {
            return 0;
        }
        sort(intervals.begin(),intervals.end());
        int count=0;
        int last_included=0;
        
        for(int i=1;i<intervals.size();i++)
        {
            
            if(intervals[last_included][1] <= intervals[i][0])
            {
                last_included=i;
            }
            else
            {
                count++;
                //taking the shorter interval
                if(intervals[i][1] < intervals[last_included][1])
                {
                    last_included=i;
                }
            }
        }
        
        return count;
    }
};