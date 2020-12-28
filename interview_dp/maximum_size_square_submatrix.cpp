int Solution::solve(vector<vector<int> > &arr) {
    int ans=0;
    
    //check if all the values in 1st row and 1st col are 0 ..ese atleast 1 size sqr sub mat is possuble
    
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i][0]==1)
        {
            ans=1;
            break;
        }
    }
    
    for(int i=0;i<arr[0].size();i++)
    {
        if(arr[0][i]==1)
        {
            ans=1;
            break;
        }
    }
    
    for(int i=1;i<arr.size();i++)
    {
        for(int j=1;j<arr[0].size();j++)
        {
            if(arr[i][j]!=0)
            {
                arr[i][j]=1+min({arr[i-1][j],arr[i-1][j-1],arr[i][j-1]});
                ans=max(ans,arr[i][j]);
            }
        }
    }
    
    return ans*ans;
}
