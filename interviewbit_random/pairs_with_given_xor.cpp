int Solution::solve(vector<int> &nums, int target) {

    unordered_map<int,int>mp;
    
    int count=0;
    for(int i=0;i<nums.size();i++)
    {
        if(mp.find(nums[i]^target)!=mp.end())
        {
            count++;
        }
        else
        {
            mp[nums[i]]++;
        }
    }
    return count;
}
//3|6|8|10|15|50
//target=5
/*
i=0
find 3^5==mp.end
3|1

i=1
6^5=3 !=mp.end
count=1

i=2
find 8^5==mp.end
3|1
8|1

i=3
find 10^5==mp.end
3|1
8|1
10|1

i=4
find 15^5=10 !=mp.end
count=2

i=5
find 50^5==mp.end
3|1
8|1
10|1
50|1

end
return count=2
*/