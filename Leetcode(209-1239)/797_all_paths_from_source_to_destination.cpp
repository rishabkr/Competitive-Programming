class Solution {
public:
    
    void print1(vector<int>&vec)
    {
        cout<<endl;
        for(int i=0;i<vec.size();i++)
        {
            cout<<i<<" ";
        }
    }
    
    void print2(vector<vector<int>>&vec)
    {
        cout<<endl;
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec[i].size();j++)
            {
                cout<<vec[i][j]<<" ";
            }
        cout<<endl;
        }
    }

    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int t=g.size()-1;
        vector<vector<int>> ans;
        queue<vector<int>>q;
        q.push({0});
        
        while(!q.empty()){
            vector<int>v=q.front();
            q.pop();
           // print1(v);
            int node=v.back();
            if(node==t){
                ans.push_back(v);
                continue;
            }
            for(int i=0;i<g[node].size();i++){
                vector<int>temp=v;
                temp.push_back(g[node][i]);
                q.push(temp);
            }
            
        }
        //print2(ans);
            
        return ans;
    }
};