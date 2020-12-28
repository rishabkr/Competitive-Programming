class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
       ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int right_shift_counter=0;
        while(m!=n)
        {
            m=m>>1;
            n=n>>1;
            right_shift_counter++;
        }
        return m<<right_shift_counter;
    }
};

/*
1000
1010
-----
100
101
-----
10
10
now they are equal and shft_counter=2
result=10 left_shift shift_counter_times
10<<2=1000=8 answer
    */