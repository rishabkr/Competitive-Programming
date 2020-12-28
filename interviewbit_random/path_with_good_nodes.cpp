int result;
int num;
void dfs(int v, int count, vector<int> &A, vector<bool> vis, vector<vector<int>> &adj){
    vis[v]=1;
    
    for(int child: adj[v]){
        if(vis[child]==0){
            if(A[child-1]) dfs(child, count+1, A, vis, adj);
            else dfs(child, count, A, vis, adj);
        }
    }
    if(adj[v].size()==1 && count<=num) result++; //is a leaf
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n=A.size();
    result=0;
    num=C;
    vector<bool> vis(n+1, false);
    vector<vector<int>> adj(n+1);
    
    for(int i=0; i<n-1; i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    if(A[0]==1) dfs(1, 1, A, vis, adj);
    else dfs(1, 0, A, vis, adj);
    return result;
}