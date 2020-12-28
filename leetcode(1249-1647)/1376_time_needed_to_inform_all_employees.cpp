class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n,vector<int>());
        
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
            {
                adj[manager[i]].push_back(i);
            }
        }
        
        queue<pair<int,int>>q;
        
        q.push({headID,0});
        int res=0;
        
        while(!q.empty())
        {
            auto front=q.front();
            q.pop();
            
            int curr_employee_id=front.first;
            
            int curr_time=front.second+informTime[curr_employee_id];
            
            res=max(res,curr_time);
            
            for(auto subordinate : adj[curr_employee_id])
            {
                q.push({subordinate,curr_time});
            }
        }
        
        return res;
    }
};

/*class Solution {
public:
    vector<int>adj[1000005];
    int dfs(int headid,vector<int>&inform_time)
    {
        int max_time=0;
        for(auto i: adj[headid])
        {
            max_time=max(max_time,dfs(i,inform_time));
        }
        
        return inform_time[headid]+max_time;
    }
    
    
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        return dfs(headID,informTime);
    }
};
*/

