class Solution {
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
};


/*class Solution {
public:
    
    bool is_equal(unordered_map<string,int>&mp1,unordered_map<string,int>&mp2)
    {
        bool equal=true;
        for(auto item : mp1)
        {
            if(mp2[item.first]==item.second)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    return true;
    }
    
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
        
        while(i < s.length()-concat_len+1)
        {
            string sub=s.substr(i,concat_len);
            
            unordered_map<string,int>mp2;
            
            int k=0;
            int n=0;
            while(k < words.size())
            {
                string temp=sub.substr(n,single_word_len);
                mp2[temp]++;
                k++;
                n+=single_word_len;
            }
            
            if(is_equal(mp1,mp2))
            {
                res.push_back(i);
            }
        
            i++;
        }
        
        return res;
    }
};*/