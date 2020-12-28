#define mod 1000000007
int Solution::chordCnt(int n) {

    vector<long long int >catalan(n+1);
    catalan[0]=1;
    catalan[1]=1;
    
    for(long long int i=2;i<=n;i++)
    {
        long long int left=0;
        long long int right=i-1;
        
        while(left <= i-1)
        {
            catalan[i]=( catalan[i]+ (catalan[left]%mod * catalan[right])%mod ) %mod;
            left++;
            right--;
        }
    }
    return catalan[n]%mod;
}
