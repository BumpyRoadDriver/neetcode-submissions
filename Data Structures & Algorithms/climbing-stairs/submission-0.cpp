class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n; 
        int two_prev = 1; 
        int one_prev = 2; 

        for(int i = 3; i <= n; i++){
            one_prev += two_prev; 
            two_prev = one_prev - two_prev;
        }
        return one_prev;
    }
};
