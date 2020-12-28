class StockSpanner {
public:
    stack<int>stk;
    map<int,int>mp;
    StockSpanner() {
    }
    
    int next(int price) {
        if(stk.empty())
        {
            stk.push(price);
            mp[price]=1;
            return mp[price];
        }
        int span=0;
        while(!stk.empty() and price >= stk.top())
        {
            span=span+mp[stk.top()];
            stk.pop();
        }
        
        stk.push(price);
        mp[price]=span+1;
        return mp[price];
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */