class Solution {
public:
    int count=0;
    void bin_search(vector<int>&arr2,int ele,int low,int high,int d)
    {
        while(low<=high)
        {
        int mid=(low)+(high-low)/2;

        if(abs(arr2[mid]-ele)<=d)
        {
            return;
        }
        if(arr2[mid]<ele)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        }
        count++;
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++)
        {
            bin_search(arr2,arr1[i],0,arr2.size()-1,d);
        }
        return count;
    }
};