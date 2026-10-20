class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        set<pair<int,int>> st;; 

        if (n == 1) return 0 ;
        int i = 0; 
        while(i < n and (not height[i])){i++;}
        int j = i+1;; 
        int ans = 0; 
        int cur =  0; 
        while(j < n){
            if (height[j] >= height[i]){
                ans += cur;
                i = j; 
                j = i+1;
                cur = 0;
            }
            else{
                cur += (-height[j] + height[i]);
                j++;
            }
        }
        if (i == n-1) return ans; 
        for(int k = i+1; k < n; k++){
            st.insert({-height[k], k});
        }

        while(true){
            auto val = (st.begin() -> first);
            j = st.begin() -> second;
            st.erase(st.begin());
            for(int a = i+1; a < j; a++){
                ans += abs(val + height[a]);
                st.erase({-height[a], a});
            }
            i = j; 
            j = i+1;
            if (j >= n) break;
        }
        return ans;


    }
};
