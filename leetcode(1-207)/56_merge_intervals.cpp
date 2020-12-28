class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1 or !intervals.size())
        {
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        vector<int>curr_interval=intervals[0];
        res.push_back(curr_interval);
         
        for(int i=1;i<intervals.size();i++)
        {
            if(res.back()[1]>=intervals[i][0])
            {
                res.back()[1]=max(intervals[i][1],res.back()[1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};