class Solution {
public:
    
    int distance(vector<int>&a, vector<int>&b)
    {
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        vector<int>dists={
            distance(p1,p2),
            distance(p1,p3),
            distance(p1,p4),
            distance(p2,p3),
            distance(p2,p4),
            distance(p3,p4),            
        };
        
        unordered_map<int,int>mp;
        for(int dist : dists)
        {
            mp[dist]++;
        }
        
        if(mp.size()!=2)
        {
            return false;
        }
        
        for(auto p : mp)
        {
            return p.second==2 or p.second==4;
        }
        return false;
    }
};