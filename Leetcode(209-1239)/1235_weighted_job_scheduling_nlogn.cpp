class Solution {
public:
    
    struct Job{
        int start;
        int finish;
        int profit;
    };
    vector<Job>jobs;
    
    static bool comp(Job &a,Job &b)
    {
        return a.finish < b.finish;
    }
    
    // int get_first_nonoverlapping_index(int index)
    // {
    //     for(int j=index-1;j>=0;j--)
    //     {
    //         if(jobs[j].finish <= jobs[index].start)
    //         {
    //             return j;
    //         }
    //     }
    //     return -1;
    // }
    
  
    int get_first_nonoverlapping_index(int index)
    {
        int low=0;
        int high=index-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(jobs[mid].finish <= jobs[index].start)
            {
               if(jobs[mid+1].finish <= jobs[index].start)
               {
                   low=mid+1;
               }
               else
                {
                    return mid;
                }
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
  
    
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        int n=start.size();
        if(n==0)
        {
            return 0;
        }
        
        for(int i=0;i<n;i++)
        {
            Job job;
            
            job.start=start[i];
            job.finish=end[i];
            job.profit=profit[i];
            
            jobs.push_back(job);
        }
        
     
        sort(jobs.begin(),jobs.end(),comp);

        vector<int>dp(n,0);
        dp[0]=jobs[0].profit;
        
        for(int i=1;i<n;i++)
        {
            int current_profit=jobs[i].profit;
          
            int available_index=get_first_nonoverlapping_index(i);
    
            if(available_index!=-1)
            {
                current_profit+=dp[available_index];
            }
            dp[i]=max(current_profit,dp[i-1]);
        }
       
        return dp[n-1];
    }
};