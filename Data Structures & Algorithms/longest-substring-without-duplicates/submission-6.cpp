class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256]; 
        for(int i = 0; i < 256; i++)freq[i] = 0; 
        if (s.size() <= 1) return s.size();
        int i = 0; int j = 0; 
        int n = s.size(); 
        int ans = 0;
        while(i <= j and j < n){
            char b= s[j];
            if (freq[b]){
                // cout << "Break: \n" << "i: " << i << "\nj: " << j << endl;
                ans = max(ans, j-i);
                
                while(s[i] != s[j]){
                    freq[s[i++]]--;
                }
                i++;
            }
            else{
                freq[b]++;
                
            }
            j++;
        }   
        return max(ans, j-i);
    }
};
