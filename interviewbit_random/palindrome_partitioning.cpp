    
    bool is_palindrome(string s)
    {
        int i=0;
        int j=s.length()-1;
        if(i>=j)
        {
            return true;
        }
        while(i<j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
    
        return true;
    }
    
    void find_all_partitions(string s,vector<vector<string>>&res,vector<string>temp)
    {
        if(s.length()==0)
        {
            res.push_back(temp);
        }
        
        for(int i=0;i<s.length();i++)
        {
            string left_partition=s.substr(0,i+1);
            
            if(is_palindrome(left_partition))
            {
                temp.push_back(left_partition);
                
                find_all_partitions(s.substr(i+1),res,temp);
                    
                temp.pop_back();
            }
        }
    }


vector<vector<string> > Solution::partition(string s) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

       vector<vector<string>>res;
        
        find_all_partitions(s,res,{});
        
        return res;
    
    
}
