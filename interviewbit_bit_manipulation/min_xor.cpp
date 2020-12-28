int Solution::findMinXor(vector<int> &arr) {
    sort(arr.begin(),arr.end());
    int min_xor=INT_MAX;
    
    for(int i=0;i<arr.size()-1;i++)
    {
        int xorr=arr[i]^arr[i+1];
        if(xorr < min_xor)
        {
            min_xor=xorr;
        }
    }
    return min_xor;
}
