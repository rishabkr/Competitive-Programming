class Solution {
public:
    
    void print(vector<vector<int>>vec)
    {
        for(auto i : vec)
        {
            for(auto j : i)
            {
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
    
    
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        vector<bool>ans;
        vector<vector<int> >v(26,vector<int>(s.size()+1,0));
		//count the char at every index
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<26;j++)
            {
                if(s[i]-'a'==j)v[j][i+1]=v[j][i]+1;
                else v[j][i+1]=v[j][i];
            }
        }
        
        print(v);
        // iterate for each query
        
        cout<<"============\n";
        
        for(int i=0;i<q.size();i++)
        {
            int start=q[i][0],end=q[i][1]+1,c=q[i][2],t=0;
			//find the char which count is odd.
            for(int j=0;j<26;j++)
            {   
                //cout<<char(i+97)<<"\t"<<t<<"\n";
                t+=(v[j][end]-v[j][start])%2;
            }
            if(c>=t/2)ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};