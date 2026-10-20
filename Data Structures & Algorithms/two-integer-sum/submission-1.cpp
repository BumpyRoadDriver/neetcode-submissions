class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, pair<int,int>> hmap; 
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];

            if (hmap.find(num) != hmap.end()){
                hmap[num].second = (hmap[num].second == -1)? i: hmap[num].second; 
            }
            else{
                hmap[num] = {i, -1};
            }
        }

        for(auto num: nums){
            if (num * 2 == target){
                if (hmap[num].second != -1){
                ans.push_back(hmap[num].first);
                ans.push_back(hmap[num].second);
                return ans;}
            }
            else{
                if (hmap.find(target -num) != hmap.end()){
                    ans.push_back(hmap[num].first);
                    ans.push_back(hmap[target-num].first);
                    return ans;
                }
            }
        }
        
    }
};
