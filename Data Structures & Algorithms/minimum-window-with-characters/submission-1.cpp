class Solution {
public:
    bool check_match(int curr[], int target[]){
        for(int i= 0; i < 128; i++){
            if (curr[i] < target[i]) return false;
        }

        return true;
    }

    string minWindow(string s, string t) {
        if (s.size() < t.size()) return ""; 
        
        int target[128] ={0};
        for(auto c: t) target[c]++; 
        bool found = false;
        pair<int,int> ans = {-1, -1}; 
        int l = 0; int r = 0; 

        int curr[128] = {0};
        int n = s.size();
        while(r < n){   
            curr[s[r]]++; 
            bool match = (check_match(curr, target));

            if (match and not found){
                found = true;
                ans = make_pair(l, r);
            }

            if (match){
                // keep running down the left pointer till we unmatch
                while(l <=r and match){
                    curr[s[l]]--;
                    l++; 
                    match = check_match(curr, target);

                }
                
                // found a better ans 
                if (ans.second - ans.first + 1 > r - (l-1)+1){
                    ans = make_pair(l-1, r);
                }
            }
            r++;
        }

        if (not found) return "";
        return s.substr(ans.first, ans.second - ans.first+1);


    }
};
