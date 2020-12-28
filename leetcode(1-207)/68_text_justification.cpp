class Solution {
public:
    string left_justify(vector<string>&words,int diff,int i,int j)
    {
        int spaces_on_right=diff-(j-i-1);
        string res;
        res.append(words[i]);
        for(int k=i+1;k<j;k++)
        {
            res.append(" "+words[k]);
        }
        for(int m=0;m<spaces_on_right;m++)
                {
                    res.append(" ");
                }

        return res;
    }
    
        string middle_justify(vector<string>&words,int diff,int i,int j)
    {
            int spaces_needed=j-i-1;
            int spaces=diff/spaces_needed;
            int extra_spaces=diff%spaces_needed;
            string res;
            res.append(words[i]);
            for(int k=i+1;k<j;k++)
            {
                int spaces_to_apply=spaces+ (extra_spaces > 0 ? 1:0);
                extra_spaces--;
                for(int m=0;m<spaces_to_apply;m++)
                {
                    res.append(" ");
                }
                res.append(words[k]);
            }
            return res;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        int i=0;
        int n=words.size();
        while(i<n)
        {
            int j=i+1;
            int line_length= words[i].length();//stores num of chars in words
            while(j<n and (line_length+words[j].length()+(j-i-1)<maxWidth)) //j-i-1=number of sectionsbetween words
            {
                line_length+=words[j].length();
                j++;
            }
            
            int diff=maxWidth-line_length;//amount of spaces to aplply in line
            int num_words=j-i; //num words in line
            //now we'll find whether to left justify or full
            if(num_words==1 or j>=n)//last word
            {
                res.push_back(left_justify(words,diff,i,j));
            }
            else
            {
                res.push_back(middle_justify(words,diff,i,j));
            }
            i=j;
        }
        
        return res;
    }
};