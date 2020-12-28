class Solution {
public:
    void rotate(vector<int>& arr, int k) {
     
        k=k%arr.size();//1 2 3 4 5 6 7 ,k=3
        reverse(arr.begin(),arr.end()); // 7,6,5,4,3,2,1
        reverse(arr.begin(),arr.begin()+k);//5,6,7,4,3,2,1
        reverse(arr.begin()+k,arr.end());//5,6,7,1,2,3,4

       
    }
};