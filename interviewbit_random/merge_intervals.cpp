/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 void print(vector<Interval>vec)
 {  
  
     for(auto it :vec)
     {
         cout<<it.start<<","<<it.end<<" ";
     }
     cout<<"\n";
 }
 
 
 
 bool comp(Interval a,Interval b)
 {
     return a.start < b.start;
 }
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval new_interval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    intervals.push_back(new_interval);
    
    sort(intervals.begin(),intervals.end(),comp);
      
    vector<Interval>merged_intervals;
    merged_intervals.push_back(intervals[0]);
    
    for(int i=1;i<intervals.size();i++)
    {   
        
        auto interval=intervals[i];
        
        if(interval.start <= merged_intervals.back().end)
        {
            merged_intervals.back().end = max(merged_intervals.back().end,interval.end);
        }
        else
        {
            merged_intervals.push_back(interval);
        }
    }
//print(merged_intervals);
return merged_intervals;
    
}
