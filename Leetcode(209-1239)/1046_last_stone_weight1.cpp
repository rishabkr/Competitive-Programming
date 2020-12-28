class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>pq;
        
        for(int stone : stones)
        {
            pq.push(stone);
        }
        
        while(pq.size()>1)
        {
            int stone1=pq.top();pq.pop();
            int stone2=pq.top();pq.pop();
            
            if(stone1==stone2)
            {
                continue;
            }
            else
            {
                if(stone1 > stone2)
                {
                    pq.push(stone1-stone2);
                }
                else
                {
                    pq.push(stone2-stone1);
                }
            }
        }
        return (pq.size() == 1)?pq.top():0;
    }
};