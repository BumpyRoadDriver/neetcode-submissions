class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> psum(nums.size()+1, 1); 
        vector<int> ssum(nums.size()+1, 1); 

        for(int i = 0; i < nums.size(); i++){
            psum[i+1] *= nums[i] * psum[i];
        }
        for(int i = nums.size()-1; i >= 0; i--){
            ssum[i]*=nums[i]*ssum[i+1];
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = psum[i] * ssum[i+1];
        }
        return nums;
    }
};
