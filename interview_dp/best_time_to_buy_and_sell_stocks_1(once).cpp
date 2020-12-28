int Solution::maxProfit(const vector<int> &nums) {
    
    int max_prof=0;
    int minp=INT_MAX;
    for(int num : nums)
    {
        minp=min(minp,num);
        max_prof=max(max_prof,num-minp);
    }
    return max_prof;
}
