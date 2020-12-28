class Solution {
public:
    
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>people(num_people);
        int i=0;
        
        int loops=0;
        while(candies>0)
        {
            if(i==num_people)
            {
                loops++;
                i=0;
            }
            int current_candy=(loops*num_people)+(i+1);
            if(candies-current_candy<0)
            {
                people[i]+=candies;
            }
            else
            {
                people[i]+=current_candy;
            }
            i++;
            candies-=current_candy;
        }
            return people;
            }
};