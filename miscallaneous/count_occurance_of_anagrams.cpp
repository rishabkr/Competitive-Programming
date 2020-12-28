class Solution{
public:

	int search(string pat, string txt) {
	   
	   int n=txt.length();
	   int k=pat.length();
	   int count=0;
        
       vector<int>pat_hash(26,0),text_hash(26,0);
       
       for(int i=0;i<k;i++)
       {
           pat_hash[pat[i] - 'a']++;
           text_hash[txt[i] - 'a']++;
          
       }
       
       if(pat_hash == text_hash)
      {
          count++;
      }
    
        for(int i=0; i + k < n ; i++)
        {
            text_hash[txt[i]- 'a']--;
            text_hash[txt[i + k] - 'a']++;
            
            count+=(pat_hash == text_hash);
        }
      
	   return count;
	}

};