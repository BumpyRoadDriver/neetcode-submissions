class Solution {
public:
    int longestConsecutive(vector<int> nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(auto it = st.begin(); it != st.end(); it++){
            int num = *it ;
            if (st.count(num-1))continue;

            int length = 1; 
            while(st.count(num+length)){
                length++;
            }
            ans = max(ans, length);
        }
        return ans;
    }
};