int Solution::solve(vector<int> &A) {
    int even = 0, odd = 0;
    
    for (int i = 0; i < A.size(); i++)
        if (i %2 == 1)
            odd += A[i];
        else
            even += A[i];
    
    int odd_left = 0, even_left = 0, ans = 0;
    
    for (int i = 0; i < A.size(); i++) {
        if (i %2 == 1) 
            odd -= A[i];
        else 
            even -= A[i];
            
        if (odd_left + even == even_left + odd)
            ans++;
        
        if (i %2 == 1)
            odd_left += A[i];
        else
            even_left += A[i];
    }
    
    return ans;
}