class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>distance(n,vector<int>(n,1e4));
     
        for(int i=0;i<edges.size();i++)
        {
            int from=edges[i][0];
            int to=edges[i][1];
            int dist=edges[i][2];
            distance[from][to]=dist;
            distance[to][from]=dist;
        
        }
        
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==j)
                    {
                        distance[i][j]=0;
                    }
                    distance[i][j]=min(distance[i][j],distance[i][k] + distance[k][j]);
                }
            }
        }
        
        vector<int>city_count(n,0);
        int count=INT_MAX;
        int res=0;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(distance[i][j] <= distanceThreshold and i!=j)
                {
                    c++;
                }
            }
            if(count >= c)
            {
                count=c;
                res=i;
            }
        }
        
        return res;
    }
};