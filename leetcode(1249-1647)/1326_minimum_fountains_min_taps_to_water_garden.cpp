class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        int max_range_covered=0;
        int min_range_start=0;
        int open_taps=0;
        int index=0;
        int garden_size=n;
        
        while(max_range_covered < garden_size)
        {
            for(int i=index ; i< ranges.size(); i++) //i can start from 0 also, but with index=i its faster.
            {
                if( i - ranges[i] <= min_range_start and i + ranges[i] >= max_range_covered)
                {
                    max_range_covered= i + ranges[i];
                    index=i;
                }
            }
            
            if(min_range_start == max_range_covered) //no change in min and max was found,means atleast one part cant be covered
            {
                return -1;
            }
            
            open_taps++;
            min_range_start=max_range_covered;
        }
        
        return open_taps;
    }
};