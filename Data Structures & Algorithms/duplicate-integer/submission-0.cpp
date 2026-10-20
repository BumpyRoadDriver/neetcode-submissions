class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> freq; 

        for (int num: nums){
            freq[num]++;
            if (freq[num] >1){
                return true;
            }
        }
        return false;
    }
};