class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string prefix;
        
        ///sort beforehand as the suggetion needs to be in lexic order
        vector<vector<string>>results;
        sort(products.begin(),products.end());
        
        for(auto c: searchWord)
        {
            //add curr char to prefix
            
            prefix.push_back(c);
            
            auto it=lower_bound(products.begin(),products.end(),prefix);
            
            vector<string>suggestions;
            
            for(int i=0;i<3 and it+i < products.end();i++)
            {
                if((*(it+i)).find(prefix)!=string::npos)
                {
                    suggestions.emplace_back(*(it+i));
                }
                else
                {
                    break;
                }
            }
            results.push_back(suggestions);
        }
        return results;
    }
};