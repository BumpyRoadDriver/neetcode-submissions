class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int product = 1; 
        int flag = 0;
        int fi = -1;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if (not num) {flag++;
            if (flag == 1){
                fi = i;
            }}

            if (i != fi){
product = (long long int) num * product;
            }
            
        }

        if (flag > 1){
             vector<int> t(nums.size());
             return t;
        }
        else if (flag == 1){
            vector<int> t(nums.size()); 
            t[fi] = product;
            return t;
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                nums[i] = product/nums[i];
            }
            return nums;
        }

        
        vector<int> ans(nums.size()); 
        for(int i =0 ;i < ans.size(); i++){
            ans[i] = (product/ nums[i]);
        }
        return ans;
    }
};
