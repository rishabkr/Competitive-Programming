int Solution::snakeLadder(vector<vector<int> > &ladders, vector<vector<int> > &snakes) {
    
    unordered_map<int,int>mp;
    
    for(auto ladder : ladders)
    {
        mp[ladder[0]]=ladder[1];
    }
    for(auto snake : snakes)
    {
        mp[snake[0]]=snake[1];
    }
    int ans=0;
    queue<int>q;
    q.push(1);
    
    vector<bool>visited(110,0);
    
    while(!q.empty())
    {
       
       int qsize=q.size();
        for(int i=0;i<qsize;i++)
        {
            int current=q.front();
            q.pop();
            
            if(current==100)
            {
                return ans;
            }
            
            if(visited[current])
            {
                continue;
            }
            visited[current]=true;
            for(int j=1;j<=6;j++)
            {
                int next=current+j;
                
                if(next > 100)
                {
                    continue;
                }
                if(mp.find(next)!=mp.end())
                {
                    next=mp[next];
                }
                q.push(next);
            }
        }
        ans++;
    }
return -1;
}