
bool is_valid(vector<int>&arr,int mid,int k)
{
    int num_students=1;
    int num_books=0;
    
    for(int i=0;i<arr.size();i++)
    {
        num_books+=arr[i];
        
        if(num_books > mid)
        {
            num_students++;
            num_books=arr[i];
        }
        
        if(num_students > k)
        {
            return false;
        }
    }
    return true;
}

int Solution::books(vector<int> &arr, int k) {
    
    if(k > arr.size())// if number of students are more than number of books
    {
        return -1;
    }
    
    int max_element=INT_MIN;
    int sum=0;
    for(int ele : arr)
    {
        max_element=max(max_element,ele);
        sum+=ele;
    }
    
    int left=max_element;
    int right=sum;
    int res=-1;
    while(left <= right)
    {
        int mid=left+(right-left)/2;
        
        if(is_valid(arr,mid,k)==true)
        {
            res=mid;
            right=mid-1;
            
        }
        else
        {
            left=mid+1;
        }
    }
    return res;
}
