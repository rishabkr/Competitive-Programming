vector<int> Solution::dNums(vector<int> &arr, int k) {
    vector<int> ans;
    if(k>arr.size())
        return ans;
    unordered_map<int,int> map;
    for(int i=0;i<k;i++){
        map[arr[i]]++;
    }
    ans.push_back(map.size());
    for(int i=k;i<arr.size();i++){
        
        int temp = arr[i-k];
        map[temp]--;//release
        
        if(map[temp]==0){
             map.erase(temp);//release
             map[arr[i]]++; //acquire
             ans.push_back(map.size());
        }
        else{
            map[arr[i]]++;
            ans.push_back(map.size());
        }
    }
    return ans;
}