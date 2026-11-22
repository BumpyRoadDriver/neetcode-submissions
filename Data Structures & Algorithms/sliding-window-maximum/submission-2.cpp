class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums; 
        int n = nums.size();
        deque<pair<int,int>> dq;
        dq.push_back(make_pair(nums[0], 0));
        vector<int> ans(n -k +1);

        for(int i= 1; i < n; i++){
            while(dq.size() and dq.back().first < nums[i]){
                dq.pop_back();
            }
            dq.push_back({nums[i], i});

            while(dq.front().second <= i-k){
                dq.pop_front();
            }
            if (i >= k-1)
                ans[i-(k-1)] = dq.front().first;
        }
        return ans;
    }
};
