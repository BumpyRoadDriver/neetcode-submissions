class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> smax(prices.size()+1, 0); 
        for(int i= prices.size()-1; i >= 0; i--){
            smax[i] = max(smax[i+1], prices[i]);

        }

        int n = prices.size() ; int ans{}; 
        for(int i =0; i < n-1; i++){
            ans = max(ans, smax[i+1]-prices[i]);
        }
        return ans;
    }
};
