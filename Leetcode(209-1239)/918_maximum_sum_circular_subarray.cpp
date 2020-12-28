class Solution {
public:
    
    int kadanes_max(vector<int>&arr)
    {
        int current=arr[0];
        int best=arr[0];
        
        for(int i=1;i<arr.size();i++)
        {
            current=max(current+arr[i],arr[i]);
            best=max(current,best);
        }
        return best;
    }
    
        pair<int,int> kadanes_min(vector<int>&arr)
    {
        int current=arr[0];
        int best=INT_MAX;
        int total_sum=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            total_sum+=arr[i];
            current=min(current+arr[i],arr[i]);
            best=min(current,best);
        }
        return {best,total_sum};
    }

    
    
    int maxSubarraySumCircular(vector<int>& A) {
        
        int max_sum=kadanes_max(A);
        auto mins_res=kadanes_min(A);
        int min_sum=mins_res.first;
        int total_sum=mins_res.second;
        
        if(max_sum > 0 )
        {
            return max(max_sum,total_sum-min_sum);
        }
        return max_sum;
        
        
    }
};


/*class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int max_sum=INT_MIN;
        int min_sum=INT_MAX;
        
        int max_ending_here=0;
        int min_ending_here=0;
        
        int total_sum=0;
        
        for(auto arr_i : A)
        {
            total_sum+=arr_i;
            
            max_ending_here=max(max_ending_here+ arr_i, arr_i);
            max_sum=max(max_sum,max_ending_here);
            
            min_ending_here=min(min_ending_here + arr_i, arr_i);
            min_sum=min(min_sum,min_ending_here);            
        }
        
        if(max_sum > 0 )
        {
            return max(max_sum,total_sum-min_sum);
        }
        return max_sum;
        
        
    }
};*/