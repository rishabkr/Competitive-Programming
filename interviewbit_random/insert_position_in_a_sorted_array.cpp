
int binary_search(vector<int>& arr,int target)
{
    int start=0;
    int end=arr.size()-1;
    int res=0;
    while(start<=end)
    {
        int mid=start + (end-start)/2;
        
        if(arr[mid] == target)
        {   
            return mid;
        }
        if(arr[mid] < target)
        {
            start=mid+1;
        }
        if(arr[mid] > target)
        {
            end=mid-1;
        }
    }
    return start;
}

int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return binary_search(A,B);
}
