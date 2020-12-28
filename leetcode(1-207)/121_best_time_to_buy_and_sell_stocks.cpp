class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
        {
            return 0;
        }
        int prof=0;
        int min_price=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min_price)
            {
                min_price=prices[i];
            }
            else if(prices[i]-min_price>prof)
            {
                prof=prices[i]-min_price;
            }
        }
        return prof;
    }
};