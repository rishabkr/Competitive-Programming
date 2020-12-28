 class NumArray {
	vector<int> arr;
public:
	NumArray(vector<int>& nums) {
		arr=nums;
		for(int i=1;i<nums.size();i++){
			arr[i]=nums[i]+arr[i-1];
		}
	}

	int sumRange(int i, int j) {
		if(i==0) return arr[j];
		else{
			return arr[j]-arr[i-1];
		}
	}
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
