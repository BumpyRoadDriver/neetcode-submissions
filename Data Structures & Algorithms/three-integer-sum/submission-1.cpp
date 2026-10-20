class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size(); 
        vector<vector<int>> ans_st;
        for(int k = 0; k < n-2; k++){
            if (k and nums[k] == nums[k-1]) continue; 
            int i = k+1;
            int j = n-1; 
            int target = -nums[k];
            while(i < j){
                int sum = nums[i] + nums[j]; 
                if (sum == target){
                    ans_st.push_back({nums[k], nums[i], nums[j]}); 
                    while(i < n-1 and nums[i+1] == nums[i]){
                        i++;
                    }
                    if (i >= j) break;
                    while(j > 1 and nums[j-1] == nums[j]) {j--;}
                    i++; j--;
                    if (i >= j) break;
                }
                else if (sum < target){
                    i++;
                }
                else j--;
            } 
        }
        return ans_st;
    }
};



