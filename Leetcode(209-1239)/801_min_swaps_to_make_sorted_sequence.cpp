class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>no_swap(n,0);
        vector<int>swap(n,1);
        
        
        for(int i=1;i<n;i++)
        {
            
            swap[i]=n;
            no_swap[i]=n;
            //if elements are in order without swap
            if(A[i-1] < A[i] and B[i-1] < B[i])
            {
                no_swap[i]=no_swap[i-1];
                swap[i]=swap[i-1]+1;
            }
            
            //if elements are in order without a swap
            if(A[i-1] < B[i] and B[i-1]< A[i] )
            {
                no_swap[i]=min(no_swap[i],swap[i-1]);
                
                swap[i]=min(swap[i],no_swap[i-1]+1);
            }

        }
        
        return min(swap[n-1],no_swap[n-1]);
    }
};