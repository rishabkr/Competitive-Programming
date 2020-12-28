
void largest(string str, int k, string &max)
{
    if(k == 0)
        return;
    int n = str.length();
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(str[i]<str[j])
            {
                swap(str[i],str[j]);
                if(str.compare(max)>0)
                {
                    max = str;
                }
                largest(str, k-1, max);
                swap(str[i],str[j]);
            }
        }
    }
}

int main() {
	//code
	int t,k;
	string str;
	cin>>t;
	while(t>0)
	{
	    cin>>k;
	    cin>>str;
	    string max = str;
	    largest(str, k, max);
	    cout<<max<<"\n";
	    t--;
	}
	return 0;
}