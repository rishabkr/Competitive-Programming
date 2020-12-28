class Solution {
public:
    
   /*
   Idea is to keep track of the sums, and then store the sum%K in arrays.
   Whenever there are 2 indexes of same modulus sum,it means the subarray sum between them
   is divisible by K.If there are multiple such indexes then ways of choosing them for creating a subarray
   is nC2 where n is the count of the sum%K's occured in that array. if zero sum also occurs we ans will be nc2+N
   */ 
    
    int mod(int x,int k)
    {
        return ((x%k)+k)%k;
    }
    
    int subarraysDivByK(vector<int>& A, int k) {
        vector<int>mod_count(k,0);
        int n=A.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+= mod(A[i],k);
            mod_count[sum%k]++;
        }
        int number_of_subarrays=0;
        //0 sum needs to be taken in advance
        number_of_subarrays=mod_count[0];
        for(auto count : mod_count)
        {
            number_of_subarrays+=(count*(count-1))/2;
        }
        return number_of_subarrays;
    }
};