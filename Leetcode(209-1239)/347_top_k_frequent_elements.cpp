bool sorted(const pair<int,int>&a,const pair<int,int> &b)
    {
        return a.second>b.second;
    }

class Solution {
public:
        
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=-0;i<nums.size();i++)
        {
            mp[nums[i]]+=1;
        }
        vector<pair<int,int>>vec;
        for(auto it:mp)
        {
            vec.emplace_back(make_pair(it.first,it.second));
        }
        sort(vec.begin(),vec.end(),sorted);
        vector<int>res;
        for(auto it=vec.begin();it!=vec.begin()+k;it++)
        {
            res.push_back(it->first);
        }
    return res;
    }
};