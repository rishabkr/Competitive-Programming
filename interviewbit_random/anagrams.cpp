vector<vector<int> > Solution::anagrams(const vector<string> &strings) {
    //[act,dgo,dgo,act]
    //mp[act]=1,mp[dgo]=2,mp[dgo]=2,3,mp[act]=1,4
     //[[1,4],[2,3]]
     vector<vector<int>>res;
     vector<string>sorted_strings;
     unordered_map<string,vector<int>>mp;
     
     for(auto str : strings)
     {
        sort(str.begin(),str.end());
        sorted_strings.push_back(str);
     }
     
     for(int i=0;i<sorted_strings.size();i++)
     {
         mp[sorted_strings[i]].push_back(i+1);
     }
    
    for(auto occurances : mp)
    {
        res.push_back(occurances.second);
    }
    return res;
}