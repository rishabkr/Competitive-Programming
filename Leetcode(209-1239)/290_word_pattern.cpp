class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string>char_mp;
        unordered_map<string,char>word_mp;
        
        stringstream ss(str);
        
        int i=0;
        int n=pattern.size();
        string word;
        while(ss >> word)
        {
            if(i==n)
            {
                return false;
            }
            
            char c=pattern[i];
            
            if(char_mp.count(c) != word_mp.count(word))
            {
                return false;
            }
            
            if(char_mp.count(c))
            {
                if((word_mp[word]!=c) or (char_mp[c]!=word))
                {
                    return false;
                }
            }
            
            else
            {
                char_mp.insert({c,word});
                word_mp.insert({word,c});
            }
          i++;
        }
        return i==n;
        
    }
};