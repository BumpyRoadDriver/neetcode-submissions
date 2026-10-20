class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(); 
        if (n ==1) return nums[0];
        else if(nums[0]>nums[1] ) return nums[1];
        else if (nums[0] < nums.back()) return nums[0];

        int lo = 1; int hi = n-1; 
        while(lo <=hi){
            int mid = (lo + hi)/2; 

            if (nums[mid] >= nums[0]){
                lo = mid+1;
            }
            else {hi = mid-1;}
        }
        // if (lo == n) return nums
        return nums[lo];
    }
};
