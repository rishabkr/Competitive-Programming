int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for(int i = 0; i< A.size(); i++)
        if(A[i] <= 0 || A[i] > n)    A[i] = n+1;
        
    for(int i = 0; i< A.size(); i++)
    {
        if(abs(A[i]) == n+1)
            continue;
        int num = abs(A[i]);
        if(A[num-1] > 0)     // If negative then already set as visited
            A[num-1] *= -1;
    }
    for(int i = 0; i< A.size(); i++)
        if(A[i] > 0) return i+1;
        
    
    return n+1;
}