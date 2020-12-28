class Solution {
public:
    
    void swap(string &s,int i,int j)
    {
      
    }
    
    int maximumSwap(int number) {
        string num=to_string(number);
         int last_index[10]={0}; //last position of digit i
        for(int i = 0 ; i<num.length();i++)
        {
            last_index[num[i]-'0']=i;
        }
        
        for(int i=0;i<num.length() ; i++)
        {
            for(int d=9;d > num[i]- '0' ; d--)
            {
                if(last_index[d] > i)
                {

                      char temp=num[i];
                                           

                      num[i]=num[last_index[d]];
                                          

                      num[last_index[d]]=temp;

                    return stoi(num);
                }
            }
        }
        return number;
    }
};