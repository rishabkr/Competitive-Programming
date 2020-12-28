class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
        int max_sum=arr[0];
        int curr_sum=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            curr_sum=max(arr[i],curr_sum+arr[i]);
            if(curr_sum >  max_sum)
            {
                max_sum=curr_sum;
            }
        }
        return max_sum;
    }
};