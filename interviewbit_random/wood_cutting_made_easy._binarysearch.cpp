#define ll long long
int Solution::solve(vector<int> &height, int required) {

    int minn=0;
    int maxx=INT_MIN;
    for(int ht : height)
    {
        maxx=max(maxx,ht);
    }
    ll ans=0;
    while(minn <= maxx)
    {
        long long mid=minn + (maxx-minn)/2;
        
        ll wood=0;
        
        for(int i=0;i<height.size();i++)
        {
            if(height[i]-mid > 0)
                wood+=height[i]-mid;
        }
        
        if(wood >= (ll)required)
        {
            minn=mid+1;
            ans=max(ans,mid);
        }
        else
        {
            maxx=mid-1;
        }
    }
    return ans;
}
