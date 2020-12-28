void generate_sum(vector<vector<int>>& answer, vector<int> current, vector<int>& nums, set<vector<int>>& S, int target)
{
    int n = nums.size();
    if(target < 0) return; // if target < 0 return no need to go forward
    if(target == 0)
    {
        sort(current.begin(), current.end()); // sort the current collection
        if(S.insert(current).second == false) // if it already exists
            return;                           // return because no duplicates
        S.insert(current);                    // if not, current to the set
        answer.push_back(current);            // add current to the answer
        return;
    }
    
    for(int i = 0; i<n; i++)
    {
        current.push_back(nums[i]);            // let's take the ith element
        target -= nums[i];                     // then target would reduce to target - nums[i]
        generate_sum(answer, current, nums, S, target); // now apply same algo with updated target
        current.pop_back();                    // let's skip the ith element and not take if
        target += nums[i];                     // since we removed changed the target above we restore it
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &nums, int target) 
{
    vector<int> current;
    vector<vector<int>> answer;
    set<vector<int>> S;
    generate_sum(answer, current, nums, S, target);
    sort(answer.begin(), answer.end());
    return answer;
}