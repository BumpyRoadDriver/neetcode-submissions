class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size(); 
        set<vector<int>> ans_st;
        for(int k = 0; k < n-2; k++){
            int i = k+1;
            int j = n-1; 
            int target = -nums[k];
            while(i < j){
                int sum = nums[i] + nums[j]; 
                if (sum == target){
                    ans_st.insert({nums[k], nums[i], nums[j]}); 
                ++i; j--;
                }
                else if (sum < target){
                    i++;
                }
                else j--;
            } 
        }
        vector<vector<int>> ans; 

        for(auto &vec: ans_st){
            ans.push_back(vec);
        }
        return ans;
    }
};
