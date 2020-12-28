int Solution::solve(vector<int> &A) {
    unordered_map<int,int>mp;
    for(int a : A)
    {
            mp[a]+=1;
    }
    for(int a: A)
    {
        if(mp[a]>1)
        {
            return a;
        }
    }
    
    return -1;
}
//single pass
/*int Solution::solve(vector<int> &A) {
    int n=A.size();
    int min=-1;
    unordered_map<int, int> b;
    for(int i=n-1;i>=0;i--){
        b[A[i]] +=1;
       if(b[A[i]] > 1) min=A[i];
    }
    
    
    return min;
}*/