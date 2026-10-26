class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        if (n == 1) return 0; 
        if (n < 3) return min(cost[0], cost[1]);

        pair<int,int> p = {0, min(cost[0], cost[1])};
        for(int i = 3; i <= n; i++){
            int new_cost = min(p.first + cost[i-2], p.second + cost[i-1]);
            swap(p.first, p.second); 
            p.second = new_cost;
        }

        return p.second;

    }
};
