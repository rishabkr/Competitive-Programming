#include<bits/stdc++.h>

using namespace std;


vector<int> construct_lps_array(string pattern)
{

vector<int>lps_array(pattern.length());

lps_array[0]=0;

int index=1;
int length=0;

while(index < pattern.length())
{

	if(pattern[index]==pattern[length])
	{
		length++;
		lps_array[index]=length;
		index++;
	}
	else
	{
		if(length)
		{
			length=lps_array[length-1];
		}
		else
		{
			lps_array[index]=0;
			index++;
		}
	}

}

return lps_array;

}

vector<int> kmp_pattern_search(string pattern,string text)
{

	vector<int>lps_array=construct_lps_array(pattern);
    
	vector<int>occurances;

	for(int text_index=0,pattern_index=0; text_index < text.length() ; )
	{
		if(pattern[pattern_index] == text[text_index])
		{
			pattern_index++;
			text_index++;
		}

		if(pattern_index == pattern.length())
		{
			occurances.push_back(text_index-pattern_index);
			pattern_index=lps_array[pattern_index-1];
		}


		else if(text_index < text.length() and pattern[pattern_index] != text[text_index])
		{
			if(pattern_index)
			{
				pattern_index=lps_array[pattern_index-1];
			}
			else
			{
				text_index+=1;
			}

		}

	}


	if(!occurances.size())
	{
		cout<<"-1\n";
	}

return occurances;
}


int main()
{

string text,pattern;
cout<<"Enter string to search in \n";
cin>>text;

cout<<"Enter search pattern \n";
cin>>pattern;

auto res=kmp_pattern_search(pattern,text);

cout<<"Item occurred at : \n";

for(auto item :res)
{
	cout<<item<<" ";
}

return 0;

}