class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0; int ans{};
        for(int i = prices.size()-1; i >= 0; i--){
            ans = max(ans, mx - prices[i]);
            mx = max(mx, prices[i]);
        }
        return ans;
    }
};
