#include<bits/stdc++.h>
using namespace std;

int largest_2_pow_less_than_n(int n)
{
    int x=0;
    
    while((1<<x) <= n)
    {
        x++;
    }
    return x-1;
}


int solve(int A) {
    ll n=A;
    
    if(n==0)
    {
        return 0;
    }
    
    ll x = largest_2_pow_less_than_n(n);
    
    ll sum_bits_to_2_pow_n= x*(1<<(x-1)); //x*2^(x-1)
    
    ll sum_bits_2_pow_n_to_n= n - (1 << x) +1; //n-2^x+1
    
    ll remaining= n - (1 << x);
    
    ll ans= sum_bits_to_2_pow_n + sum_bits_2_pow_n_to_n + solve(remaining);
    return int(ans%1000000007);


int main()
{
	int n;
	cin>>n;

	cout<<solve(n);
}

/*#define ll long long int
int largest_2_pow_less_than_n(int n)
{
    int x=0;
    
    while((1<<x) <= n)
    {
        x++;
    }
    return x-1;
}


int Solution::solve(int A) {
    ll n=A;
    
    if(n==0)
    {
        return 0;
    }
    
    ll x = largest_2_pow_less_than_n(n);
    
    ll sum_bits_to_2_pow_n= x*(1<<(x-1)); //x*2^(x-1)
    
    ll sum_bits_2_pow_n_to_n= n - (1 << x) +1; //n-2^x+1
    
    ll remaining= n - (1 << x);
    
    ll ans= sum_bits_to_2_pow_n + sum_bits_2_pow_n_to_n + solve(remaining);
    return int(ans%1000000007);
}
*/