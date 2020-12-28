class Solution {
public:
    
    static bool comp(pair<char,int>a,pair<char,int>b)
    {
     return a.second > b.second;   
    }
    
    string frequencySort(string s) {
        map<char,int>mp;
        for(char c : s)
        {
            mp[c]++;
        }
        vector<pair<char,int>>freq;
        for(auto it : mp)
        {
            freq.push_back(it);
        }
        sort(freq.begin(),freq.end(),comp);
        string res;
        for(auto item : freq)
        {
            while(item.second !=0)
            {
                res.push_back(item.first);
                item.second--;
            }
        }
        return res;
    }
};