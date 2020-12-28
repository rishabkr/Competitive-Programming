int find_pivot(const vector<int> &arr)
{
    int n=arr.size();
    int left=0;
    int right=arr.size()-1;
    
    while(left<=right)
    {
        if(arr[left]<=arr[right])
        {
            return left;
        }
        
        int mid=left+(right-left)/2;
        
        int previous=(mid-1+n)%n;
        int next=(mid+1)%n;
        
        if(arr[mid] <= arr[previous] and arr[mid]<=arr[next])
        {
            return mid;
        }
        
        if(arr[left] <= arr[mid])
        {
            left=mid+1;
        }
        else if(arr[mid] <= arr[right])
        {
            right=mid-1;
        }
    }
    return -1;
}

int binary_search(int target,const vector<int> &arr,int start,int end)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        
        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[mid] < target)
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

int Solution::search(const vector<int> &arr, int target) {
    
    int pivot_index=find_pivot(arr);
    
    int left_index=binary_search(target,arr,0,pivot_index-1);
    int right_index=binary_search(target,arr,pivot_index,arr.size()-1);
    
    if(left_index!=-1)
    {
        return left_index;
    }
    if(right_index!=-1)
    {
        return right_index;
    }
    return -1;
}
