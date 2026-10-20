class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> dict; 

        for(auto str: strs){
            string t = str; 

            sort(t.begin(), t.end()); 
            dict[t].push_back(str);
        }

        vector<vector<string>> sol; 
        for(auto &[key, val]: dict){
            sol.push_back(val); 
        }
        return sol; 
    }
};
