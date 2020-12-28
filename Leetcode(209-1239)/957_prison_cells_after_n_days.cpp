class Solution {
public://https://www.youtube.com/watch?v=XaayRYdKG0I&t=46s
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<string,int>mp;
        for(int i=0;i<N;i++)
        {
            string s(cells.begin(),cells.end());
            
            if(mp.find(s)!=mp.end())
            {
                int loop_length= i-mp[s];
                int remaining_days=(N-i)%loop_length;
                return prisonAfterNDays(cells,remaining_days);
            }
            else
            {
                mp[s]=i;
                int prev=cells[0];
                for(int j=1;j<7;j++)
                {
                    int next=cells[j+1];
                    int curr=cells[j];
                    cells[j]=prev==next;
                    prev=curr;
                }
            }
            cells[0]=0;
            cells[7]=0;
        }
        return cells;
    }
};