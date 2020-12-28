class Solution {
public:
    bool contains_cycle;
    bool dfs(int node,vector<int>&visited,vector<int>&onstack,vector<vector<int>>&adj)
    {
        visited[node]=1;//inprocess
        
        for(auto i : adj[node])
        {
            if(visited[i]==1)
            {
                return true;
            }
            if(visited[i]==0 and dfs(i,visited,onstack,adj))
            {
                return true;
            }
        }
        
        visited[node]=2;//finished
        //stack will contain schedule in reverse topological sorted order
        onstack.push_back(node); 
        return false;
  }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses,0);
        vector<int>onstack;
        vector<vector<int>>adj(numCourses);
      
        for(auto i : prerequisites)
        {
            adj[i[1]].push_back(i[0]);
        }
    
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0 and dfs(i,visited,onstack,adj))
            {
                return {};
            }
        }
        
        reverse(onstack.begin(),onstack.end());
        return onstack;
    }
};