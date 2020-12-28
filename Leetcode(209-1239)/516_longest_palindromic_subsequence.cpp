class Solution {
public:
    int string_lcs(string s,string t)
    {
        int lcs[s.length()+1][t.length()+1];
        for(int i=0;i<=s.length();i++)
        {
            for(int j=0;j<=s.length();j++)
            {   
                if(i==0||j==0)
                {
                    lcs[i][j]=0;
                }
             else if(s[i-1]==t[j-1])
                {
                    lcs[i][j]=lcs[i-1][j-1]+1;
                }
                else
                {
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }
        return lcs[s.length()][t.length()];
    }
    int longestPalindromeSubseq(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string t=string(s.rbegin(),s.rend());
        return string_lcs(s,t);
    }
};