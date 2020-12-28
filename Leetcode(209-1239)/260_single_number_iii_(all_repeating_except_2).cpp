class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xxory=0;
        //find xor of 2 numbers == xor of all numbers
        for(auto num : nums)
        {
            xxory=xxory^num;
        }
        //find right most set bit mask
        int rmsb= xxory & -xxory;
        
        int x=0;
        int y=0;
        //find xor whose rmsb is on separately and off separately //helps in extracting the two numbers
        for(auto num : nums)
        {
            if((num & rmsb) == 0)
            {
                x=x^num;
            }
            else
            {
                y=y^num;
            }
        }
        return {x,y};
    }
};