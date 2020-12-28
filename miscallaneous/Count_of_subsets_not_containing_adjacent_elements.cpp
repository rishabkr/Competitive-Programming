// C++ implementation of the approach 
#include <iostream> 
using namespace std; 
  
// Function to return the count 
// of possible subsets 
int cntSubsets(int* arr, int n) 
{ 
    int a[n], b[n]; 
  
    a[0] = b[0] = 1; 
  
    for (int i = 1; i < n; i++) { 
  
        // If previous element was 0 then 0 
        // as well as 1 can be appended 
        a[i] = a[i - 1] + b[i - 1]; 
  
        // If previous element was 1 then 
        // only 0 can be appended 
        b[i] = a[i - 1]; 
    } 
  
    // Store the count of all possible subsets 
    int result = a[n - 1] + b[n - 1]; 
  
    return result; 
} 


Method 3; If we take a closer look at the pattern, we can observe that the count is actually (N + 2)th Fibonacci number for N ≥ 1.

n = 1, count = 2 = fib(3)
n = 2, count = 3 = fib(4)
n = 3, count = 5 = fib(5)
n = 4, count = 8 = fib(6)
n = 5, count = 13 = fib(7)