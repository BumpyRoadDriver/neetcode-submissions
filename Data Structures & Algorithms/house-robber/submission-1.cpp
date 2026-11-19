class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size(); 

        if (n == 1) return nums.back(); 
        else if (n == 2) return max({nums[0], nums[1]}); 
        else{
            int a = nums[0];
            int b = max(nums[0], nums[1]);

            for(int i =2; i < n; i++){
                int tb = b;
                b = max(b, a + nums[i]);
                a = tb;
            }
            return b;
        }
    }
};
