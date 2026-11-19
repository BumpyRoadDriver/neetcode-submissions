class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        // check every pair of points 
        // we can reuse the information contained inside substrings inside
        // we'll have to iterate using distance 
        // dp[i][j] = -1 means that s[i..j] does not make a substring


        // every single char is a palindrome
        for(int i = 0; i < n; i++){
            dp[i][i] = 1; 
        }
        pair<int,int> ans = {0,0};
        // every pair of characters is a palindrome only if both are the same 
        for(int i = 0; i < n-1; i++){
            dp[i][i+1] = (s[i] == s[i+1])? 2: -1; 
            ans = (s[i] == s[i+1])? make_pair(i, i+1): ans;
        }


        for(int dist = 2; dist < n; dist++){
            for(int i = 0; i < n - dist; i++){
                int j = i + dist; 

                // if the substring inside is a palindrome and border characters
                // match then we have a new palindrome
                if (s[i] == s[j] and (dp[i+1][j-1] != -1)){
                    dp[i][j] = dp[i+1][j-1] + 2; 
                    ans = {i, j};
                }

            }
        }
        return s.substr(ans.first, ans.second - ans.first+1);
        
    }
};
