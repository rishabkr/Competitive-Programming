class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        vector<bool>visited(arr.size()+1,0);
         
        stack<int>q;
        q.push(start);
      
        while(!q.empty())
        {
            
            int current=q.top();
            q.pop();
            
            int left=current - arr[current];
            int right=current + arr[current];
            
            if(left >= 0 and !visited[left])
            {
                visited[left]=true;
                q.push(left);
                
                if(arr[left] == 0)
                {
                    return true;
                }
            }
            
            if(right < arr.size() and !visited[right])
            {
                visited[right]=true;
                q.push(right);
                
                if(arr[right] == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};