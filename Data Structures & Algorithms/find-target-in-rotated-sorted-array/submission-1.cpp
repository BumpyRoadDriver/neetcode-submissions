class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(); 
        if (n ==1) return 0;
        else if(nums[0]>nums[1] ) return 1;
        else if (nums[0] < nums.back()) return 0;

        int lo = 1; int hi = n-1; 
        while(lo <=hi){
            int mid = (lo + hi)/2; 

            if (nums[mid] >= nums[0]){
                lo = mid+1;
            }
            else {hi = mid-1;}
        }
        // if (lo == n) return nums
        return lo;
    }

    int search(vector<int>& nums, int target) {
        int n= nums.size(); 
        if (nums[0] == target) return 0;
        else if(n ==1) return -1; 
        int min_idx = findMin(nums); 

        int lo, hi;
        if (min_idx == 0 or nums[0] <= target and target <= nums[((n+(min_idx-1))%n)]){
            lo = 1; hi = (n + min_idx-1) % n; 
        }
        else{
            lo = min_idx; hi = n-1;
        }

        auto it = lower_bound(next(nums.begin(), lo), next(nums.begin(), hi+1), target);
        if (it != nums.end() and *it == target) return distance(nums.begin(), it);
        return -1;
    }
};
