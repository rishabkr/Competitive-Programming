int Solution::wordBreak(string word, vector<string> &dict) {
    
    
    unordered_map<string,int>mp;
  
    
     for(auto w: dict)
    {
        mp[w]+=1;
    }
    
    if(mp.find(word)!=mp.end())
    {
        return true;
    }

    vector<bool>breakable(word.length()+1,false);
 
    vector<int>true_index;//save all the matching indexes where dp[i]==1;
    
    true_index.push_back(-1);
    
    for(int i=0;i<=word.length();i++)
    {
        for(int j=true_index.size()-1;j>=0;j--)
        {
                if(mp[ word.substr( true_index[j]+1, i-true_index[j] ) ]>0)
                {
                    breakable[i+1]=true;
                    true_index.push_back(i);
                    break;
                }
            
        }
    }
    return breakable[word.length()];
}



