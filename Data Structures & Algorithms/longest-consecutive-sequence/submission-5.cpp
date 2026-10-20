class Solution {
public:
    int longestConsecutive(vector<int> nums) {
        unordered_map<int,int> dp; 
        unordered_map<int, bool> seen;
        if(not nums.size()){
            return 0;
        }
        for(auto num: nums){
            dp[num]++;
        }
        int ans = 1;
        for(auto &[k, v]: dp){
            if (seen.find(k) != seen.end()){
                continue;
            }
            int size = 1; 

            seen[k]= true; 
            int i = k+1; 
            while(dp.count(i)){
                seen[i] = true;
                i++;
                size++;
            }
            i = k-1; 
            while(dp.count(i)){
                seen[i]= true;
                size++;
                i--;
            }
            ans = max(ans, size);
        }
        return ans;
    }
};