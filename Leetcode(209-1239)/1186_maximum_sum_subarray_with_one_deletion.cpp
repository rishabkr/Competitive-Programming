class Solution {
public:
    
    void print(vector<int>&arr)
    {
        for(auto num :arr)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    
    int maximumSum(vector<int>& arr) {
        
        int highest=INT_MIN;
       
        for(auto num : arr)
         {
             highest=max(highest,num);
         }
        
        if(highest < 0)
        {
            return highest;
        }
        
        vector<int>maximum_sum_left(arr.size());
        vector<int>maximum_sum_right(arr.size());
        
        int curr_ans=0;
        
        for(int i=0 ; i < arr.size();i++ )
        {
         
            curr_ans=max(arr[i],curr_ans + arr[i]);
            
            
            maximum_sum_left[i]=curr_ans;
            
        }
        
        int best=0;
        curr_ans=0;
        
        for(int i=arr.size()-1 ; i >= 0; i-- )
        {
         
            curr_ans=max(arr[i],curr_ans + arr[i]);
            
            best=max(curr_ans,best);
            
            maximum_sum_right[i]=(curr_ans);
            
        }
        
        //print(maximum_sum_left);
        
        //print(maximum_sum_right);
        
        
        int result=best;
        
        for(int i=1;i<arr.size()-1 ; i++)
        {
            result=max(result,maximum_sum_left[i-1]+maximum_sum_right[i+1]);
        }
        
        return result;
    }
};