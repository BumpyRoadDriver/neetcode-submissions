class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n <= 1) return n; 

        int cnt[26]= {0};
        int l = 0; int r = 0; int ans = 1;
        while(l <= r and r < n){
            int window_size = r-l+1; 
            char c = s[r];
            cnt[c-'A']++; 
            int top_freq = *max_element(cnt, cnt+26);
            if (window_size - top_freq <= k){
                ans = max(ans, window_size);
                
            }
            else{
                cnt[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
