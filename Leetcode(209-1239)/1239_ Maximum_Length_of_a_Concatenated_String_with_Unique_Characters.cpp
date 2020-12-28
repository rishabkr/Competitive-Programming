class Solution {
  int max_length=0;
    
    public:
  
    int maxLength(vector<string>& arr) {
        
        find_max_length("" , arr , 0);
        
        return max_length;
    }

    bool contains_unique_characters(string s)
    {
        bool visited[26]={0};
        for(char c : s)
        {
            if(visited[c-'a'])
            {
                return false;
            }
            visited[c-'a']=1;
        }
        return true;
    }
    
    
    void find_max_length(string str,vector<string>&arr,int index)
    {
        if(!contains_unique_characters(str))
        {
            return;
        }
        if(str.size() > max_length)
        {
            max_length=str.size();
        }
        
        for(int i= index; i < arr.size(); i++ )
        {
            find_max_length(str + arr[i],arr,i+1);
        }
    }
};

  