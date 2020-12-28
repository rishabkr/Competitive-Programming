int Solution::isPalindrome(string str) {
    
    int i=0;
    int j=str.length()-1;
    
    while(i < j )
    {
        if(tolower(str[i])==tolower(str[j]))
        {
            i++;
            j--;
        }
        else if(!isalnum(str[i]))
        {
            i++;
        }
        else if(!isalnum(str[j]))
        {
            j--;
        }
        else
        {
        return 0;
        }
    }
    return 1;
}
