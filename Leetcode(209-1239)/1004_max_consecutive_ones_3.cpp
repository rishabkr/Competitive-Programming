class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int i=0;
        int j=0;
        
        while( j < arr.size())
        {
            
            if(arr[j]==0)
            {
                k--;
            }
            if(k < 0)
            {
                if(arr[i]==0)
                {
                    k++;
                }
                i++;
            }
            j++;
        }
        
        return j-i;
    }
};