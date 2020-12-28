class Solution {
public:
    int binary_search(vector<int>&arr,int start,int end,int target)
    {
            
        while(start<=end)
        {
            
            int mid=end+(start-end)/2;
            //cout<<arr[mid]<<" ";
            if(arr[mid]==target)
            {
                return mid;
            }
            else if(arr[mid] < target)
            {
                start=mid+1;
            }
            else if(arr[mid] > target)
            {
                end=mid-1;
            }
        }
        return -1;
    }
    
    int find_pivot_index(vector<int>&arr)
    {
        int start=0;
        int end=arr.size()-1;
        int n=arr.size();
        
        while(start<=end)
        {
            if(arr[start]<=arr[end])
            {
                return start;
            }
            
            int mid=start+(end-start)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            
            if(arr[mid] <= arr[prev] and arr[mid]<=arr[next])
            {
                return mid;
            }
            if(arr[start]<=arr[mid])
            {
                start=mid+1; //go towards unsorted side
            }
            else if(arr[mid]<=arr[end])
            {
                end=mid-1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int pivot_index=find_pivot_index(nums);
        int search_left=binary_search(nums,0,pivot_index-1,target);
        
        int search_right=binary_search(nums,pivot_index,nums.size()-1,target);
        
        if(search_left!=-1)
        {
            return search_left;
        }
        if(search_right!=-1)
        {
            return search_right;
        }
        return -1;
    }
};