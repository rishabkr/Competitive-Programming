class Solution:
            
    def canPartition(self, nums: List[int]) -> bool:
        def subset_sum(nums,target):
                arr=[[False for _ in range(target+1)] for _ in range(len(nums)+1)]
            
                for i in range(len(nums)+1):
                    arr[i][0]=True
                for i in range(1,len(nums)+1):
                    for j in range(1,target+1):
                        if(j>=nums[i-1]):
                            arr[i][j]=arr[i-1][j-nums[i-1]] or arr[i-1][j]
                        else:
                            arr[i][j]=arr[i-1][j]
                return arr[len(nums)][target]

        arr_sum=sum(nums)
        if(arr_sum%2 == 1):
            return False
        else:
            return subset_sum(nums,int(arr_sum/2))