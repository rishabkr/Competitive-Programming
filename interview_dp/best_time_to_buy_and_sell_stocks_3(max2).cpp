int Solution::maxProfit(const vector<int> &prices) {

    int b1=INT_MAX;
    int b2=INT_MAX;
    int p1=0;
    int p2=0;
    
    for(int i=0;i<prices.size();i++)
    {
        b1=min(b1,prices[i]);
        p1=max(p1,prices[i]-b1);
        
        b2=min(b2,prices[i]-p1);
        p2=max(p2,prices[i]-b2);
        
    }
    return p2;
}
