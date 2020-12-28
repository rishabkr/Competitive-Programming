class Solution {
public:
    int countBinarySubstrings(string s) {
        int current=1;
        int result=0;
        int prev=0;
        
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
            {
                current++;
            }
            else
            {
                prev=current;
                current=1;
            }
            if(current <= prev)
            {
                result++;
            }
        }
        return result;
    }
};

/*
initially, result = 0, prev = 0 current = 1
First iteration :: i = 1
s[1] == s[0], true
current = 2
current <= prev, false

Second iteration :: i = 2
s[2] == s[1], false
prev = 2;
current = 1; // Main logic starts here now you see 2 0's and 1 1's => so 1 result string '01' string can be formed
current <= prev, (1 <= 2), true
result++ // result = 1

Third iteration :: i = 3
s[3] == s[2], true
current = 2;
current <= prev, (2 <= 2), true
result++ // result = 2 (becoz of string '0011')

Fourth iteration :: i = 4
s[4] == s[3], false
prev = 2;
current = 1;
current <= prev, (1 <= 2), true
result++ // result = 3

Fifth iteration :: i = 5
s[5] == s[4], true
current = 2;
current <= prev, (2 <= 2), true
result++ // result = 4

Sixth iteration :: i = 6
s[6] == s[5], false
prev = 2;
current = 1;
current <= prev, (1 <= 2), true
result++ // result = 5

Seventh iteration :: i = 7
s[7] == s[6], true
current = 2;
current <= prev, (2 <= 2), true
result++ // result = 6
*/