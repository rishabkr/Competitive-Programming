    unordered_map<char,vector<char>>mp;
    vector<string>res;
    
    void backtrack(int index,string digits,string &temp)
    {
        
        if(index == digits.length())
        {
             res.push_back(temp);
            return;
        }
        
        for(char ch : mp[digits[index]])
        {
            temp.push_back(ch);
            backtrack(index+1,digits,temp);
            temp.pop_back();
        }
        
        
    }

vector<string> Solution::letterCombinations(string digits) {
        if(digits.length()==0)
        {
            return {};
        }
        
        mp.clear();
        res.clear();
        mp['0']={'0'};
        mp['1']={'1'};
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        
        string temp="";
        backtrack(0,digits,temp);
        return res;
    }
