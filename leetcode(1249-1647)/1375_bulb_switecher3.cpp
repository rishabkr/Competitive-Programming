class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
       
        int total=0;
        int sum=0;
        int res=0;
        for(int i=0;i<light.size();i++)
        {
            sum+=light[i];
            total+=(i+1);
            if(sum==total)
            {
                res++;
            }
        }
        return res;
    }
};

