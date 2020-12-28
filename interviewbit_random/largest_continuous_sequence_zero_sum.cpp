    unordered_map<int,int>mp;
    
    int sum=0;
    int max_size=0;
    int n=A.size();
    vector<int>res;
    if( find(A.begin(), A.end(), 0) != A.end())
        res = vector<int>{0};
    mp[0] = -1;
    
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
            if(mp.find(sum)!=mp.end())
            {
                if(i - mp[sum] > res.size())
                res = vector(A.begin()+ mp[sum]+1, A.begin()+i+1);
            }
            else
            {
                mp[sum]=i;
            }
    }
    return res;
