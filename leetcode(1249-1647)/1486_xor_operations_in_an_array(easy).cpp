class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>nums(n,0);
        int _xor=0;
        for(int i=0;i<nums.size();i++)
        {
        nums[i]=start+2*i;
        _xor=_xor^nums[i];
        }
        return _xor;
    }
};