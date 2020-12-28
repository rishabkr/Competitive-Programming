class Solution {
public:
    
    
    vector<int> findAnagrams(string txt, string pat) {
            if(pat.length() > txt.length())
            {
                return {};
            }
        
            
            int n=txt.length();
	   int k=pat.length();
       vector<int>pat_hash(26,0),text_hash(26,0);
       
       for(int i=0;i<k;i++)
       {
           pat_hash[pat[i] - 'a']++;
           text_hash[txt[i] - 'a']++;
          
       }
       
        vector<int>count;
        
       if(pat_hash == text_hash)
            count.push_back(0);
    
        for(int i=0; i + k < n ; i++)
        {
            text_hash[txt[i]- 'a']--;
            text_hash[txt[i + k] - 'a']++;
            
            if(text_hash== pat_hash)
            {
                count.push_back(i+1);
            }
        }
      
	   return count;

        
    }
};