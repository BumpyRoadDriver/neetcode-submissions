class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(); 

        vector<int> ans(n-k+1); 
        multiset<int> ms; 

        for(int i = 0; i < k-1; i++){
            ms.insert(nums[i]);
        }

        for(int i= 0; i < n-k+1; i++){
            ms.insert(nums[i+k-1]); 
            ans[i] = *(ms.rbegin());
            ms.erase(ms.find(nums[i]));
        }
        return ans;
    }
};
