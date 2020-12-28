int Solution::solve(string start, string target, vector<string> &words) {
    
    if(start==target)
    {
        return 0;
    }
    
    set<string>dict;
    for(auto word : words)
    {
        dict.insert(word);
    }
    
    if(dict.find(target)==dict.end())
    {
        return 0;
    }
    
    queue<string>q;
    q.push(start);
    int count=0;
    while(!q.empty())
    {
        
        int size=q.size();
        count++;
        
        for(int i=0;i<size;i++)
        {
            string curr_word=q.front();
            q.pop();
            
            if(curr_word==target)
            {
                return count+1;
            }
            
            for(int j=0;j<curr_word.length();j++)
            {
                char temp_char=curr_word[j];
                
                for(char m='a';m<='z';m++)
                {
                    curr_word[j]=m;
                    
                    if(curr_word==target)
                    {
                        return count+1;
                    }
                    if(dict.find(curr_word)!=dict.end())
                    {
                       
                        dict.erase(curr_word);
                        q.push(curr_word);
                    }
                    else
                    {
                        continue;
                    }
                    
                }
                curr_word[j]=temp_char;
            }
            
        }
        
    }
    
    return 0;
}
