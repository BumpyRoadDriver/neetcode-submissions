class Solution {
public:
    bool isValid(string s) {
        stack<char> stk; 
        map<char,int> mp = {{'(', 1}, {'{', 2}, {
            '[', 3
        }}; 
        map<char,int> rmp = {{')', 1}, {'}', 2}, {']', 3}};
        for(auto c: s){
            if (mp.count(c)){
                stk.push(mp[c]);

            }
            else{
                if (stk.size() and stk.top() == rmp[c]){
                    stk.pop();
                }
                else return false; 
            }
        }
        return stk.empty();
    }
};
