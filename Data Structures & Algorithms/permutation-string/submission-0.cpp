class Solution {
public:
    bool comp_array(int a[]){
        for(int i = 0; i < 26; i++){if(a[i])return false;}
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.size(); 
        int m = s2.size();
        if (n > m) return false;
        // int hash[26]; for(auto &i: hash) i =0;
        int freq[26]; for(auto &i :freq) i = 0; 
        for(auto c: s1){freq[c-'a']--;}
        
        int i = 0; int j = n-1; 
        for(int k= 0; k < j ; k++){
            freq[s2[k]-'a']++;
        }

        while(j < m){
            freq[s2[j++]-'a']++;
            if (comp_array(freq)) return true;
            freq[s2[i++]-'a']--; 
        }
        return false;
        
    }
};
