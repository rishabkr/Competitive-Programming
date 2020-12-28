class Solution {
public:
    int tribonacci(int n) {
        
        int first=0;
        int second=1;
        int third=first+second;
        
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return second;
        }
        
        for(int i=0;i<n-2;i++)
        {
            int current=first + second + third;
            first=second;
            second=third;
            third=current;
        }
        return third;
    }
};

/* unordered_map<int, int> tribonaaci_val;
    int x = 0;
    int tribonacci(int n) {
        
        if(tribonaaci_val.find(n) != tribonaaci_val.end()){
            x = tribonaaci_val[n];
        }
        else if(n == 0)
            x =  0;
        else if(n == 1 || n == 2)
            x = 1;
        
        else{
            x =  tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
            tribonaaci_val[n] = x;
            
        }
        return x;
    }*/