
vector<bool>visited;
vector<bool>on_stack;
bool is_cyclic;

void dfs(int course,vector<vector<int>>&adj)
{
    visited[course]=1;
    on_stack[course]=1;
    
    for(int neighbor : adj[course])
    {
        if(on_stack[neighbor] and visited[neighbor])
        {
            is_cyclic=true;
            return;
        }
        dfs(neighbor,adj); //or if(!visited[neighbor])dfs(neighbor,adj);
    }

    on_stack[course]=0;
}


int Solution::solve(int num_courses, vector<int> &courses, vector<int> &prereq) {
    
    vector<vector<int>>adj(num_courses+100);
    
    visited.assign(num_courses+10,0);
    on_stack.assign(num_courses+10,0);
        
    is_cyclic=false;
    
    for(int i=0;i<courses.size();i++)
    {
        adj[courses[i]].push_back(prereq[i]);
    }
    
    for(int i=0;i<num_courses;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj);
        }
    }
    
    return is_cyclic==true?0:1;
}
