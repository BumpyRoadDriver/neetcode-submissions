class Solution {
public:
    int optimise(int start, int end, vector<int> &nums){
        int prev = nums[start]; 
        int curr = max(nums[start], nums[start+1]); 

        for(int i = start+2; i < end; i++){
            int temp = curr; 
            curr = max(curr, prev + nums[i]); 
            prev = temp;
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        // 2 cases. Either we pick the first or not  
        int n = nums.size(); 
        
        if (n ==1) return nums[0]; 
        else if (n == 2) return *max_element(nums.begin(), nums.end());
        else{
            // case 1: We are not allowed to pick the first house 
            // so we look at nums[2,...,n]
            int candidate_1 = optimise(0, n-1, nums); 
            int candidate_2 = optimise(1, n, nums); 

            return max(candidate_1, candidate_2);
        }
    }
};
