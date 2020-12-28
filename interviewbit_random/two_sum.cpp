
vector<int> Solution::twoSum(const vector<int> &arr, int target) {
  
  unordered_map<int,int>mp;
  
  for(int i=0;i<arr.size();i++)
  {
      int find=target-arr[i];
      
      if(mp.count(find))
      {
          return {mp[find],i+1};
      }
      else
      {
          if(mp.count(arr[i])==0)
          {
              mp[arr[i]]=i+1;
          }
      }
  }
  return {};
}



