#include<bits/stdc++.h>
using namespace std;


int main()
{

string str;
cin>>str;

string reverse_string=str;

int n=str.length();

vector<string>prefix_array;
vector<string>suffix_array;


for(int i=0;i<n;i++)
{
	string prefix=str.substr(0,i+1);
	prefix_array.emplace_back(prefix);
}

reverse(str.begin(),str.end());

for(int i=0;i<n;i++)
{
	string suffix=str.substr(0,i+1);
	reverse(suffix.begin(),suffix.end());
	suffix_array.emplace_back(suffix);

}
prefix_array.pop_back();
suffix_array.pop_back();

for(int i=0;i<n-1;i++)
{
	if(suffix_array[i]==prefix_array[i] and suffix_array[i]!=str)
	{
		cout<<suffix_array[i].length()<<"\n";
		
	}
}


return 0;
}