// int Solution::solve(vector<vector<int> > &A) {
//     int n=A.size();
//     vector<vector<int>> dp(n,vector<int>(3,0));
//     for(int i=n-1;i>=0;i--){
//         for(int j=0;j<3;j++){
//             if(i==n-1)
//             dp[i][j]=A[i][j];
//             else
//             dp[i][j]=A[i][j]+min(dp[i+1][(j+1)%3],dp[i+1][(j+2)%3]);
//         }
//     }
//     return min(dp[0][0],min(dp[0][1],dp[0][2]));
// }

int Solution::solve(vector<vector<int> > &cost) {
    
    int n=cost.size();
    
    int red=cost[0][0];
    int green=cost[0][1];
    int blue=cost[0][2];
    
    for(int i=1;i<n;i++)
    {
        
        int new_red= cost[i][0] + min(green,blue);
        int new_green=cost[i][1]+ min(red,blue);
        int new_blue=cost[i][2]+  min(red,green);
        
        red=new_red;
        green=new_green;
        blue=new_blue;
    }
    
    
    return min({red,green,blue});
}