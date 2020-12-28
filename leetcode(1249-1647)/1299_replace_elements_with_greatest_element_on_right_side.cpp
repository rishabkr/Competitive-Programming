class Solution {
public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    vector<int> replaceElements(vector<int>& arr) {
    for(int i=arr.size()-1,mx=-1;i>=0;i--)
    {
        swap(mx,arr[i]);
        mx=max(mx,arr[i]);
    }
        return arr;
    }
};