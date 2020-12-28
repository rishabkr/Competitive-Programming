class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    string addBinary(string a, string b) {
        string res="";
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        while(i>=0 or j>=0 or carry)
        {
            if(i>=0 and a[i]=='1')
                carry++;
            if(j>=0 and b[j]=='1')
                carry++;
            res.insert(0,1,carry%2==1?'1':'0');
            carry=carry/2;
            i--;j--;
        }
        return res;
    }
};