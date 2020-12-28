vector<int> Solution::maxset(vector<int> &nums) {
 long long int curr_sum=0;
 long long int  max_sum=INT_MIN;
 
 vector<int>res,temp;
 for(int i=0;i<nums.size();i++)
 {
     if(nums[i] < 0)
     {
         curr_sum=0;
         temp.clear();
         continue;
     }
     curr_sum+=nums[i];
     temp.push_back(nums[i]);
     if(curr_sum > max_sum or (curr_sum == max_sum and temp.size()>res.size()))
     {
         max_sum=curr_sum;
         res=temp;
     }
 }
 return res;
}
