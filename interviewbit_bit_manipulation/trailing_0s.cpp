int Solution::solve(int n) {

    if(n%2==1)
    {
        return 0;
    }
    int cnt=0;
    while(n%2==0)
    {
        cnt++;
        n=n/2;
    }
    return cnt;
    //OR THE BELOW
    //return log2(n&-n);
    
}


