class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> dp; 
        if(not nums.size()){
            return 0;
        }
        for(auto num: nums){
            dp[num]= 1;
        }
        sort(nums.begin(), nums.end());
        int ans    =1; 
        for(int i = nums.size()-1; i>= 0; i--){
            int num = nums[i]; 
            int t = dp[num+1]+1;
            dp[num] = t;
            ans = max(ans, t);
        }
        return ans;
    }
};
