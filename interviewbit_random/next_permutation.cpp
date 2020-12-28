vector<int> Solution::nextPermutation(vector<int> &arr) {
    int k,l;
    int n=arr.size();
    
    for(k=n-2;k>=0;k--)
    {
        if(arr[k] < arr[k+1])
        {
            break;
        }
    }
                            
    if(k<0)
    {
        sort(arr.begin(),arr.end());
    }
    else
    {
        for(l=n-1;l>k;l--)
        {
            if(arr[l] > arr[k])
            {
                break;
            }
        }
        //1 3 5 4 2
        //  k   l
        //swap k,l
        //1 4 5 3 2
        //1 4 2 3 5

        swap(arr[k],arr[l]);
        sort(arr.begin()+k+1,arr.end());
    }
    
    return arr;
}
