
void perm(int left,int right,vector<int>&arr,vector<vector<int>>&res)
{
    if(left==right)
    {
       res.push_back(arr);
       return;
    }
    else
    {
        for(int i=left;i<=right;i++)
        {
            swap(arr[i],arr[left]);
            perm(left+1,right,arr,res);
            swap(arr[i],arr[left]);
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    vector<vector<int>>res;
    perm(0,A.size()-1,A,res);
    return res;
}
