#include<stack>
class Solution {
public:
    bool isValid(string s) {
       if(s.size()%2==1) return false;
        stack<int> parentheses;
        
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                parentheses.push(c);
            }
            else{
                char t;
                if(!parentheses.empty()) t = parentheses.top();
                else return false;
                
                if((t=='('&&c==')') || (t=='['&&c==']') || (t=='{'&&c=='}')){
                    parentheses.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        return parentheses.empty();
        
    }
};