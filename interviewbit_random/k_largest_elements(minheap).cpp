vector<int> Solution::solve(vector<int> &A, int k) {
vector<int>res;
priority_queue<int,vector<int>,greater<int>>minh;

for(int i=0;i<A.size();i++)
{
    minh.push(A[i]);
    if(minh.size() > k)
    {
        minh.pop();
    }
}
while(minh.size() > 0)
{
    res.push_back(minh.top());
    minh.pop();
}
return res;
}
