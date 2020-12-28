class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int min_prod=nums[0];
        int max_prod=nums[0];
          //negative*negative can also bethe case..take care of that
        for(int i=1;i<nums.size();i++)
        {
            
            int temp_prod=max_prod;
            
            max_prod=max({max_prod*nums[i],min_prod*nums[i],nums[i]});//-ve * -ve case handled
            
            min_prod=min({min_prod*nums[i],temp_prod*nums[i],nums[i]}); //keep track of minimum so far
            
            if(max_prod > ans)
            {
                ans=max_prod;
            }
            
        }
        return ans;
    }
};

// class Solution {
// public:
//     //negative*negative can also bethe case..take care of that
//     int maxProduct(vector<int>& nums) {
//         int final_max=nums[0];
//         int curr_max_prod=nums[0];
//         int curr_min_prod=nums[0];
        
//         for(int i=1;i<nums.size();i++)
//         {
//             int temp=curr_max_prod;
            
//             curr_max_prod=max(max(curr_max_prod*nums[i],curr_min_prod*nums[i]),nums[i]);//-ve * -ve case handled
            
//             curr_min_prod=min(min(temp*nums[i],curr_min_prod*nums[i]),nums[i]); //keep track of minimum so far
            
            
//             if(curr_max_prod > final_max)
//             {
//                 final_max=curr_max_prod;
//             }
//         }
        
//         return final_max;
//     }
// };