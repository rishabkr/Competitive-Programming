class CustomStack {
    
private:
    vector<int>stk;
    int max_size=0;
public:
    int min(int a , int b)
    {
        return a<b? a:b;
    }
    
    CustomStack(int maxSize) {
        max_size=maxSize;
    }
    
    void push(int x) {
        if(stk.size() >= max_size)
        {
            return;
        }
        stk.push_back(x);
    }
    
    int pop() {
        int ans=-1;
        if(stk.size()>0)
        {
            ans=stk.back();
            stk.pop_back();
        }
        return ans;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,stk.size());i++)
        {
            stk[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */