class Solution {
public:
    
    bool is_valid(int threshold_day,vector<int>&bloom_day,int m, int k)
    {
        
        int adj_bloomed_flowers=0;
        int num_bouquet=0;
        
        for(int i=0;i<bloom_day.size(); i++)
        {
            if(bloom_day[i] > threshold_day)
            {
                adj_bloomed_flowers=0;
            }
            else
            {
                adj_bloomed_flowers++;
                
                if(adj_bloomed_flowers == k)
                {
                    num_bouquet++;
                    adj_bloomed_flowers=0;
                }
            }
        }
        
        return num_bouquet >= m;
    }
    
    int minDays(vector<int>& bloom_day, int m, int k) {
            //min_required = m*k
            
        if(bloom_day.size() < m*k)
        {
            return -1;
        }
        
        int start=*min_element(bloom_day.begin(),bloom_day.end());
        int end=*max_element(bloom_day.begin(),bloom_day.end());
        
        while(start <= end)
        {
            int mid= start + (end-start)/2;
            
            if(is_valid(mid,bloom_day,m,k))
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return start;
    }
};

     
     