vector<pair<int,int>> steps={make_pair(1,0),make_pair(0,-1),make_pair(-1,0),make_pair(0,1)};
bool isSafe(int i,int j,vector<string> &A)
{
    return (i>=0)&&(i<A.size())&&(j>=0)&&(j<A[0].size());
}



bool dfs(int i,int j,vector<string> &A, string B,int ind)
{
    if(ind==B.size()) return true;
    for(int k=0;k<4;k++)
    {
        if(isSafe(i+steps[k].first,j+steps[k].second,A)&&(A[i+steps[k].first][j+steps[k].second]==B[ind]))
        {
            if(dfs(i+steps[k].first,j+steps[k].second,A,B,ind+1)) 
            {
                return true;
            }
        }

    }
    return false;
}


int Solution::exist(vector<string> &A, string B) {
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A[0].size();j++)
            if(A[i][j]==B[0]&&dfs(i,j,A,B,1)) 
                return 1;
    return 0;
}