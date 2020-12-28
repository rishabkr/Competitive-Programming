int Solution::trailingZeroes(int A) {
    if(A<=4)
    {
        return 0;
    }
    int count=0;
    while(A/5 >0)
    {
        count=count+A/5;
        A=A/5;
    }
    return count;
}
