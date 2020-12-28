int Solution::maxProfit(const vector<int> &prices) {
    
    int max_prof=0;
    for(int i=1;i<prices.size();i++)
    {
        if(prices[i] > prices[i-1])
        {
            max_prof+=(prices[i]-prices[i-1]);
        }
    }
    return max_prof;
}
