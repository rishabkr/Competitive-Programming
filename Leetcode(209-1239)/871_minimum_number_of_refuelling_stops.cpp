class Solution {
public:
    int minRefuelStops(int target, int start_fuel, vector<vector<int>>& stations) {
        
        if(stations.size() == 0 )
        {
            if(target <= start_fuel)
            {
                return 0;
            }
            return -1;
        }
        
        priority_queue<int>pq;
        
        int current_fuel=start_fuel;
        int ans=0;
        int prev=0;
        
        for(int i=0; i<stations.size() ; i++)
        {
            int current_location=stations[i][0];
            int current_capacity=stations[i][1];
            
            current_fuel-=(current_location - prev);
            
            while(!pq.empty() and current_fuel < 0)
            {
                current_fuel+=pq.top();
                pq.pop();
                ans++;
            }
            
            if(current_fuel < 0)
            {
                return -1;
            }
            
            prev=current_location;
            pq.push(current_capacity);
        }
        
        current_fuel-=(target - prev);
        
          while(!pq.empty() and current_fuel < 0)
            {
                current_fuel+=pq.top();
                pq.pop();
                ans++;
            }
               if(current_fuel < 0)
            {
                return -1;
            }
        
        return ans;
        
    }
};