class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        vector<int> f(26);
        for(auto ch: s){
            f[ch-'a']++;
        }
        for(auto ch: t){
            f[ch-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if (f[i] != 0){
                return false;
            }
        }
        return true;
    }
};
