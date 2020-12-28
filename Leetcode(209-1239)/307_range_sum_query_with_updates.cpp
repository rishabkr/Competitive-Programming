class NumArray {
    vector<int>fenwick;
    vector<int>arr;
    int n;
    
    public:
    
    void put_val(int index,int value)
    {
        index+=1;
        
        while(index < fenwick.size())
        {
            fenwick[index]+=value;
            index=index+(index&(-index));
        }
    }
    
    NumArray(vector<int>& nums) {
        arr=nums;
        fenwick.assign(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
        {
            put_val(i,nums[i]);
        }
    
    }
    
    void update(int i, int val) {
        int difference=val-arr[i];
        arr[i]=val;
        
        put_val(i,difference);
    }
    
    int get_sum(int index)
    {
        int sum=0;
        index+=1;
        
        while(index > 0)
        {
            sum += fenwick[index];
            index -= index&(-index);
        }
        return sum;
    }
    
    int sumRange(int i, int j) {
        int left_sum=get_sum(i-1);
        int right_sum=get_sum(j);
        return right_sum-left_sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */