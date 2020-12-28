class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>word_break(s.length()+1);
        word_break[0]=true;
        for(int i=0;i<s.length()+1;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(!word_break[j])
                {
                    continue;
                }
                if(find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end())
                {
                    word_break[i]=true;
                    break;
                }
                
            }
        }
        return word_break[s.length()];
    }
};