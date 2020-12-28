class Solution {
public:
    int trailingZeroes(int n) {
        
        if(n<=4)
        {
            return 0;
        }
        
        int count=0;
        
        while(n/5 > 0)
        {
            count=count+n/5;
            n=n/5;
           
        }
    
    return count;    
    }
};