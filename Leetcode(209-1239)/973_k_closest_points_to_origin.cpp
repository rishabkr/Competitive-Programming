class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
     double dist(int a, int b)
    {
       int x2=a;
        int y2=b;
      int x1=0;
       int y1=0;
       long long int x2x1=pow((x2-x1),2);
       long long int y2y1=pow((y2-y1),2);
       double dist=sqrt(x2x1+y2y1);
        return dist;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<double,pair<int,int>>>distances;
        for(auto it:points)
        {
            double d=dist(it[0],it[1]);
            distances.push_back({d,make_pair(it[0],it[1])});
        }
        sort(distances.begin(),distances.end());
        vector<vector<int>>res;
        for(int i=0;i<K;i++)
        {
            res.push_back({distances[i].second.first,distances[i].second.second});
        }
        return res;
    }
};

/*class Solution {
public:
    
    double eucledian_distance(long long a,long long b)
    {
        return pow((a*a+b*b),0.5);
    }
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>>res;
        
        if(points.size()==0)
        {
            return res;
        }
        
        priority_queue<pair<double,pair<int,int>>>maxh;
        
        for(auto point : points)
        {
            double dist=eucledian_distance(point[0],point[1]);
            
            maxh.push({dist,{point[0],point[1]}});
            if(maxh.size()>K)
            {
                maxh.pop();
            }
        }
        
        while(maxh.size() > 0)
        {
            pair<int,int> point=maxh.top().second;
            maxh.pop();
            res.push_back({point.first,point.second});
               
        }
        
        return res;
    }
};*/