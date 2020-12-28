class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>compressed_string(chars.size()*2+1);
        
        int length=chars.size();
        
        char count[100];
        int index=0;
        int j=0;
        int result_len=0;
        
        for(index=0; index < length;index++)
        {
            compressed_string[j++]=chars[index];
            
            for(result_len=1 ; index + 1 < length and chars[index] == chars[index+1];)
            {
                result_len++;
                index++;
            }
            
            sprintf(count,"%d",result_len);
            
            for(int k=0;count[k];k++)
            {
                compressed_string[j]=count[k];
                j++;
            }
            
            compressed_string[j]='\0';
            
        }
        
        
            for(int i=0;compressed_string[i];i++)
            {
                cout<<compressed_string[i]<<"";
            }
            
 
    }
};