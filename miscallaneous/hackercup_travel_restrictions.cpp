#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

bool isallowed(vector<vector<char>>&mat,int i,int j,vector<char>&I,vector<char>&O,int n)
{
	if((O[i]=='Y' and I[j]=='Y') )
	{
		return true;
	}
	return false;
}

vector<vector<char>> generate_matrix(vector<char>&I,vector<char>&O,int n)
{
	vector<vector<char>>mat(n,vector<char>(n,'N'));
	for(int i=0;i<n;i++)
	{
		mat[i][i]='Y';
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				continue;
			}
			if(abs(i-j)==1 and isallowed(mat,i,j,I,O,n))
			{
				mat[i][j]='Y';
			}
		}
	}

for(int k=0;k<n;k++)
{
	for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
{
	if(mat[i][k]=='Y' and mat[k][j]=='Y')
	{
		mat[i][j]='Y';
	}
}	
}	
}

return mat;
}

int main()
{
	int t;
	cin>>t;
	int x=1;
			ofstream file;
file.open("submissionfinal.txt");

	while(t--)
	{
		int n;
		cout<<"\n";
		cin>>n;
		vector<char>I(n);
		vector<char>O(n);
		for(int i=0;i<n;i++)
		{
			cin>>I[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>O[i];
		}
		file<<"Case #"<<(x++)<<":\n";
		vector<vector<char>>mat=generate_matrix(I,O,n);
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				file<<mat[i][j];
			}
			file<<"\n";
		}

	}
	file.close();
	return 0;
}