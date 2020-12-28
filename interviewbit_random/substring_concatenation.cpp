
    
vector<int> Solution::findSubstring(string s, const vector<string> &words) {
    
    int l=s.length(),len=words[0].length(),num=words.size(),i,j;
    unordered_map<string,int> count,seen;
    vector<int> sol;
    string word="";
    for(auto i:words)
    {
        count[i]++;
    }
    for(i=0;i<l-len*num+1;i++)
    {
        for(j=0;j<num;j++)
    {
        word=s.substr(i+j*len,len);
        if(count.find(word)!=count.end())
        {
            seen[word]++;
            if(seen[word]>count[word])
            break;
        }
        else
            break;
    }
        if(j==num)
            sol.emplace_back(i);
        seen.clear();
    }
    return sol;


}



/*class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        if(s.length()==0 or words.size()==0)
        {
            return res;
        }
        
        unordered_map<string,int>mp1;
        
        for(auto word : words )
        {
            mp1[word]+=1;
        }
        
        int i=0;
        int concat_len=words[0].length()*words.size();
        int single_word_len=words[0].length();
        int j=0;
        while(i < s.length()-concat_len+1)
        {
            unordered_map<string,int>mp2;
            for(j=0 ; j< words.size(); j++)
            {
                string word=s.substr(i+j*single_word_len,single_word_len);
                
                if(mp1.find(word)!=mp1.end())
                {
                    mp2[word]++;
                    if(mp2[word] > mp1[word])
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if(j==words.size())
            {
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};*/