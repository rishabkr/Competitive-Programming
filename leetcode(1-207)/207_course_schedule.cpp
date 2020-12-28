class Solution {
public:
    bool contains_cycle=false;
    void dfs(int current,vector<vector<int>>&adj,vector<bool>&onstack,vector<bool>&visited)
    {
        visited[current]=true;
        onstack[current]=true;
        for(auto node:adj[current])
        {
            if(visited[node] and onstack[node])
            {
                contains_cycle=true;
                return;
            }
            if(!visited[node])
            {
                dfs(node,adj,onstack,visited);
            }
        }
        onstack[current]=false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
         vector<bool>visited(numCourses,0);
        vector<bool>onstack(numCourses,0);
        if(!prerequisites.size())
        {
            return 1;
        }
        
        for(auto &it:prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        contains_cycle=false;
        
        
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,onstack,visited);
            }
        }
        
        return contains_cycle?false:true;
    }
};