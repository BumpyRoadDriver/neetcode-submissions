class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<vector<int>> unresolvedTemps(101, vector<int>());
        int n= temperatures.size();
        if (n == 1) return {0}; 
        unresolvedTemps[temperatures[0]].push_back(0);
        for(int i = 1; i < n; i++){
            int temp = temperatures[i]; 

            for(int t = temp-1; t >=1 ; t--){
                for(auto idx: unresolvedTemps[t]){
                    temperatures[idx] = (i - idx);
                }
                unresolvedTemps[t].clear();
            }
            unresolvedTemps[temp].push_back(i);
        }

        for(int t = 1; t <= 100; t++){
            for(auto idx: unresolvedTemps[t]){
                temperatures[idx] = 0;
            }
        }


        return temperatures; 
    }
};
