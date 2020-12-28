class Solution {
public:
    int visit(int start,int end,vector<int>& gas,vector<int> &cost)
    {
        int i=start;
        int amount=0;
        while(i<end)
        {
            amount+=gas[i];
            amount-=cost[i];
            if(amount<0)
            {
                return -1;
            }
              i++;
        }
        if(i>=end)
        {
            i=0;
        }
        while(i!=start)
        {
            amount+=gas[i];
            amount-=cost[i];
            if(amount<0)
            {
                return -1;
            }
            i++;
        }
        return amount;
        
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++)
        {
            int res=visit(i,gas.size(),gas,cost);
            if(res>=0)
            {
                return i;
            }
        }
        return -1;
    }
};