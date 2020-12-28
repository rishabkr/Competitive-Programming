class Solution {
public:
    int nthUglyNumber(int n) {
    
        vector<int>ugly(n);
        ugly[0]=1;
        
        int idx2=0;
        int idx3=0;
        int idx5=0;
        
        int count=1;
        
        while(count<n)
        {
            int next2=ugly[idx2]*2;
            int next3=ugly[idx3]*3;
            int next5=ugly[idx5]*5;
            
            int next_ugly=min({next2,next3,next5});
            
            if(next_ugly==next2)
            {
                idx2++;
            }
            
            if(next_ugly==next3)
            {
                idx3++;
            }
            
            if(next_ugly==next5)
            {
                idx5++;
            }
            
            ugly[count]=next_ugly;
            count++;
        }
        return ugly[n-1];
    }
};