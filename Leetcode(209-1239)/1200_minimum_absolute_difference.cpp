class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
     sort(arr.begin(),arr.end());
     int min_diff=abs(arr[0]-arr[1]);
        vector<vector<int>>res;
        
        for(int i=1;i<arr.size();i++)
        {
            int a=arr[i];
            int b=arr[i-1];
            if(abs(b-a)<min_diff)
            {
                min_diff=abs(b-a);
            }
        }
        for(int i=1;i<arr.size();i++)
        {
            int a=arr[i];
            int b=arr[i-1];
            vector<int>temp;
            if(abs(a-b)==min_diff)
            {
                temp.push_back(b);
                temp.push_back(a);
                res.push_back(temp);
            }
        }
        return res;
    }
};