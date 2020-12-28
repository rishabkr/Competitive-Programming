
class Solution {
public:
    int numDecodings(string digits) {
    int n=digits.length();
    int count[n+1];
    
        //its like fibonacci
        count[0]=1;
        count[1]=1;
        
        if(digits[0]=='0')
        {
            return 0;
        }
        for(int i=2;i<=n;i++)
        {
            count[i]=0;
            // If the last digit is not 0,  
        // then last digit must add to the number of words 
            if(digits[i-1]>'0')
            {
                count[i]=count[i-1];
            }
            // If second last digit is smaller  
        // than 2 and last digit is smaller than 7, 
        // then last two digits form a valid character  
            if(digits[i-2]=='1' or (digits[i-2]=='2' and digits[i-1]<'7'))
            {
                count[i]+=count[i-2];
            }
        }
        
        return count[n];
    }
};


/*int countDecoding(char *digits, int n) 
{ 
    // base cases 
    if (n == 0 || n == 1) 
        return 1; 
    if (digits[0]=='0') 
          return 0; 
     
    // for base condition "01123" should return 0  
    int count = 0;  // Initialize count 
  
    // If the last digit is not 0,  
    // then last digit must add to the number of words 
    if (digits[n-1] > '0') 
        count =  countDecoding(digits, n-1); 
  
    // If the last two digits form a number smaller  
    // than or equal to 26, then consider  
    // last two digits and recur 
    if (digits[n-2] == '1' ||  
                  (digits[n-2] == '2' && digits[n-1] < '7') ) 
        count +=  countDecoding(digits, n-2); 
  
    return count; 
} */
  