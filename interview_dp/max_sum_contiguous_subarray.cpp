
int Solution::maxSubArray(const vector<int> &A) {
        
        int current=0;
        int best=INT_MIN;
        
        for(int i=0;i<A.size();i++)
        {
            
            current=max(A[i],current+A[i]);
            if(current>best)
            {
                best=current;
            }
        }
        return best;

}

