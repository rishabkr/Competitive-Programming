#include<bits/stdc++.h>
using namespace std;

void print_strings(string str,int index,string temp)
{

if(index==str.length())
{
	cout<<temp<<"\n";
	return;
}
//either space will come or will not come
print_strings(str,index+1,temp+" "+str[index]);
print_strings(str,index+1,temp+str[index]);
}


int main()
{
	string str;
	cin>>str;
	cout<<"\n";
	string temp;
	temp.push_back(str[0]);
	print_strings(str,1,temp);
	return 0;
}