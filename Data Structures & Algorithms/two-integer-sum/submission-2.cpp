class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hmap; 

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if (hmap.find(target-num) != hmap.end()){
                return {hmap[target-num], i};
            }
            hmap[num] =i;
        }
        return {};
    }
};
