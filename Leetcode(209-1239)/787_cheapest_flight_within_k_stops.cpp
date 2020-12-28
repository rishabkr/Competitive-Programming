class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto flight : flights)
        {
            int source=flight[0];
            int dest=flight[1];
            int cost=flight[2];
            
            adj[source].push_back({dest,cost});
            
        }
        
        //min heap for dijsktra
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> min_heap;
        
        min_heap.push({0,src,k+1});
        
        while(!min_heap.empty())
        {
            
            int current_cost=min_heap.top()[0];
            
            int current_node=min_heap.top()[1];
            
            int remaining_stops=min_heap.top()[2];
            
            min_heap.pop();
            
            if(dst ==  current_node)
            {
                return current_cost;
            }
            
            if(remaining_stops > 0)
            {
                for(auto neighbors : adj[current_node])
                {
                    min_heap.push({current_cost + neighbors.second,neighbors.first,remaining_stops-1});
                }
            }
            
            
        }
      return -1;   
    }
        
       
};