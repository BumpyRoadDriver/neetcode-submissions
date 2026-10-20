class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> dict; 
        for(auto num: nums){
            if (dict[num]++){
                return num;
            }
        }

    }
};
