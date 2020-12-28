class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int last_occurance[26]={0};
        
        for(int i=0;i<s.length();i++)
        {
            last_occurance[s[i]-'a']=i;
        }
        
        vector<int>res;
        
        int start=0;
        int end=0;
        
        for(int i=0;i<s.length();i++)
        {
            end=max(end,last_occurance[s[i]-'a']);
            
            if(i==end)
            {
                res.push_back(end-start+1);
                start=end+1;
            }
        }
        return res;
    }
};