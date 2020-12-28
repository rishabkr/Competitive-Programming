class Solution {
public:
    int ladderLength(string begin, string final_word, vector<string>& wordList) {
     
        set<string> st;
        for(auto word : wordList)
        {
            st.insert(word);
        }
        
        if(st.find(final_word) == st.end())
        {
            return 0;
        }
        
        queue<string> q;
        q.push(begin);
        int count=0;
        while(!q.empty())
        {
            count++;
            int q_size=q.size();
            
            for(int i=0; i< q_size; i++)
            {
                
                string current_word=q.front();
                q.pop();
                
                if(current_word ==  final_word)
                {
                    return count+1;
                }
                
                for(int j=0 ; j< current_word.length();j++)
                {
                    char current_char= current_word[j];
                    
                    for(char c = 'a' ; c <= 'z' ; c++)
                    {
                        current_word[j]=c;
                        
                        if(current_word==final_word)
                        {
                            return count+1;
                        }
                        if(st.find(current_word)==st.end())
                        {
                            continue;
                        }
                        
                        q.push(current_word);
                        st.erase(current_word);
                    }
                    current_word[j]=current_char;
                }
                
            }
            
        }
        return 0;
    }
};