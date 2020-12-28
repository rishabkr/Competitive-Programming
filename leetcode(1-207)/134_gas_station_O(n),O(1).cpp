class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& distance) {
     
        int surplus=0;
        int deficit=0;
        int start=0;
        
        for(int i=0;i<gas.size();i++)
        {
            surplus=surplus +  gas[i] - distance[i];
            
            if(surplus < 0)
            {
                start=i+1;
                deficit+=surplus;
                surplus=0;
            }
            
        }
        return (surplus+deficit) >=0 ? start : -1;
    }
};