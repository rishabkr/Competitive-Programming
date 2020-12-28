class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        
        vector<int>dp(n+1,0);//or init with $2
        dp[n]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            //daily ticket
            dp[i]=dp[i+1]+costs[0];
            
            //search for day 7 and day 30
            
            int d7=i;
            int d30=i;
            
            while(d7<n and days[d7]<days[i]+7)
            {
                d7++;
            }

            while(d30<n and days[d30]<days[i]+30)
            {
                d30++;
            }
            
            dp[i]=min({dp[i],dp[d7]+costs[1],dp[d30]+costs[2]});

        }
        return dp[0];
    }
};