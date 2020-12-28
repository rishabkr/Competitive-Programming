class Solution {
public:
    
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool isIdealPermutation(vector<int>& A) {
        int m=INT_MIN;
        for(int i=1;i<A.size();i++){
            {      //compare max value upto index of it's left side
		 if(m>A[i])return false;
            m=max(m,A[i-1]);
            }
        }
            return true;
    }
        
};
        
            
