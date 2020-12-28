#define MOD 1000000007
#define ll long long int 
int Solution::cntBits(vector<int> &A) {
    
    ll res=0;
    
    
    for(int i=0 ;i <31 ;i++)
    {
        int on_bits=0;
        
        for(int val : A)
        {
            if((val & (1<<i))!=0)
            {
                on_bits++;
            }
        }
        
        
        ll off_bits=A.size() - on_bits;
        ll ans = (on_bits * off_bits * 2);
        res= (res + ans )%MOD;
    }
    return int(res);
}
