#define mod 1000000007
int Solution::hammingDistance(const vector<int> &arr) {
    long long int res=0;
    long long int n=arr.size();
    
    for(int i=0;i<32;i++)
    { int counton=0;
        for(int val : arr)
        {
            if(val&(1<<i))
            {
                counton++;
            }
        }
        
    res+=(counton * (n-counton) * 2);
        
    }
    return res%mod;
}
