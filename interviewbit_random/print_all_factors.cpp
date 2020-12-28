vector<int> Solution::allFactors(int A) {
    if(A == 1){
       return {1};
    }
    vector<int> arr{1,A};
    for(int i = 2; i<= sqrt(A); i++){
        if(A%i == 0){
            arr.push_back(i);
            if(i != sqrt(A)) arr.push_back(A/i);
        }
    }
    sort(arr.begin(), arr.end());
    return arr;
}