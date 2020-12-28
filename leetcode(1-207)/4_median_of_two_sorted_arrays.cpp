class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int find_kth(vector<int>&nums1,int start1,vector<int>&nums2,int start2,int k)
    {
       if(start1>=nums1.size())
       {
           return nums2[start2+k-1];
       }
       if(start2>=nums2.size())
       {
           return nums1[start1+k-1];
       }
        
        if(k==1)
        {
            return min(nums1[start1],nums2[start2]);
        }
        
        int index1=start1+k/2-1;
        int index2=start2+k/2-1;
        
        int key1=index1<nums1.size()?nums1[index1]:INT_MAX; //first k/2 numbers in first and second array if first k/2 numbers in first array is smaller than k/2 number in second array then we discard the first k/2 numbers in the first array and vice versa
        int key2=index2<nums2.size()?nums2[index2]:INT_MAX;
        
        if(key1<key2)
        {
            return find_kth(nums1,start1+k/2,nums2,start2,k-k/2);
        }
        else
        {
            return find_kth(nums1,start1,nums2,start2+k/2,k-k/2);
        }
    }
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_length=nums1.size()+nums2.size();
        if(total_length&1)
        {
            return find_kth(nums1,0,nums2,0,total_length/2+1);
        }
        else
        {
            return (find_kth(nums1,0,nums2,0,total_length/2)+find_kth(nums1,0,nums2,0,total_length/2+1))*0.5;
        }
    }
};