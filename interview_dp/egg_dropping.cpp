
vector<vector<int>>dp;

int solve_egg(int e, int f)
{
    if( f==0 or f==1)
    {
        return f;
    }
    if(e==1)
    {
        return f;
    }

    if(dp[e][f]!=-1)
    {
        return dp[e][f];
    }
    
    int res=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int low,high;
        if(dp[e-1][k-1]!=-1)
        {
            low=dp[e-1][k-1];
        }
        else
        {
            low=solve_egg(e-1,k-1);
        }
        if(dp[e][f-k]!=-1)
        {
            high=dp[e][f-k];
        }
        else
        {
            high=solve_egg(e,f-k);
        }
        int temp=1+max(low,high);
        
        res=min(res,temp);
    }
    return dp[e][f]=res;
}

int Solution::solve(int e, int f) {
    if( f==0 or f==1)
    {
        return f;
    }
    if(e==1)
    {
        return f;
    }
    
    dp.assign(e+1,vector<int>(f+1,-1));
    
    solve_egg(e,f);
    
    return dp[e][f];
}


/*
USING BINARY SEARCH
int Solution::solve(int A, int B) {

vector<vector<int>> dp(A+1,vector<int>(B+1,0));

for(int i=1;i<=B;i++)
    dp[1][i]=i;

for(int i=1;i<=A;i++)
{
    dp[i][1]=1;
}
int low=0,high=0;
for(int i=2;i<=A;i++)
{
    for(int j=2;j<=B;j++)
    {
        if(i>j)             //cosidering worst case scenario
        {    dp[i][j]=dp[i-1][j];
                continue;
        }
        int t=INT_MAX;
        low=1;
        high=j;
        while(low+1<high)
        {
            int mid=(low+high)/2;
            
            if(dp[i-1][mid-1]<dp[i][j-mid])
                low=mid;
            else if(dp[i-1][mid-1]>dp[i][j-mid])
                high=mid;
            else
                high=low=mid;
                
        }
        t=1+min(max(dp[i-1][low-1],dp[i][j-low]),max(dp[i-1][high-1],dp[i][j-high]));
       
        
        dp[i][j]=t;
    }
}


return dp[A][B];
}*/