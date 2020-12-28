vector<int> Solution::intersect(const vector<int> &arr1, const vector<int> &arr2) {

vector<int>res;

int left_ptr,right_ptr=0;

while(left_ptr < arr1.size() and right_ptr<arr2.size())
{
    if(arr2[right_ptr] < arr1[left_ptr])
    {
            right_ptr++;
    }
    else if(arr1[left_ptr] < arr2[right_ptr])
    {
        left_ptr++;
    }
    
    else
    {
            res.push_back(arr1[left_ptr]);
            left_ptr++;
            right_ptr++;
    }
    
}
    return res;
}
