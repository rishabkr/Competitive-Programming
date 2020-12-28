string Solution::solve(string A) {
    vector<string>reversed;
    string res="";
    
    stringstream ss(A);
    string w;
    while(ss >> w)
    {
        reversed.push_back(w);
    }
    
    for(int i=reversed.size()-1;i>=0;i--)
    {
        res += reversed[i];
        if(i!=0)
        {
            res+=" ";
        }
    }
    
    return res;
}