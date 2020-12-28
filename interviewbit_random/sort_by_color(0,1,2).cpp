void Solution::sortColors(vector<int> &arr) {
  
  int left=0;
  int mid=0;
  int right=arr.size()-1;
  
  while(mid <= right)
  {
      switch(arr[mid])
      {
          case 0:
          swap(arr[mid],arr[left]);
          left++;
          mid++;
          break;
          
          case 1:
          mid++;
          break;
          
          case 2:
          swap(arr[mid],arr[right]);
          right--;
          break;
      }
  }
  
}
