#include<bits/stdc++.h>
using namespace std;
void print_divisors(int n)
{
	cout<<"\n";
	for(int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			if(n/i==i)
			{
				cout<<i<<"\n";
			}
			else
			{
				cout<<i<<" "<<n/i<<"\n";
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<"\n divisors are :";
	print_divisors(n);
	return 0;

}