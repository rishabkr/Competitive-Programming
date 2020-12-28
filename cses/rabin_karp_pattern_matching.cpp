#include<bits/stdc++.h>
using namespace std;
#define NUM_CHARS 256

vector<int> rabin_karp_pattern_search(string pattern,string text,int prime)
{

	int hash=1;
	int pattern_hash=0;
	int text_hash=0;

	int text_index;
	int pattern_index;
    vector<int>occurances;
    
    for(pattern_index=0; pattern_index < pattern.length()-1;pattern_index++)
    {
    	hash=(hash*NUM_CHARS)%prime;
    }

	for(pattern_index=0;pattern_index < pattern.length();pattern_index++)
	{
		pattern_hash=(NUM_CHARS*pattern_hash + pattern[pattern_index]) % prime;
		text_hash=(NUM_CHARS*text_hash + text[pattern_index]) % prime;
	}


	for(text_index=0; text_index <= text.length() - pattern.length() ; text_index++)
	{

    	if(pattern_hash == text_hash)
		{
			for(pattern_index=0; pattern_index < pattern.length(); pattern_index++)
			{
				if(text[text_index + pattern_index] !=  pattern[pattern_index])
					break;
				
			}
            

			if(pattern_index == pattern.length())
				occurances.push_back(text_index);
	
		}

		if(text_index < text.length() - pattern.length())
		{

			text_hash=(NUM_CHARS * (text_hash - text[text_index] * hash) + text[text_index+pattern.length()])%prime;
			if(text_hash < 0)
			{
				text_hash=text_hash+prime;
			}
		}

	}
	return occurances;
}


int main()
{


string text,pattern;
int prime;
cout<<"Enter string to search in \n";
cin>>text;

cout<<"Enter search pattern \n";
cin>>pattern;

cout<<"Enter Prime Number Seed \n";
cin>>prime;

auto res=rabin_karp_pattern_search(pattern,text,prime);


for(auto item :res)
{
	cout<<item<<" ";
}

return 0;


}