class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int,int>> stk; 
        int n = temperatures.size(); 
        for(int i = 0; i < n; i++){
            int temp = temperatures[i]; 

            while(stk.size() and stk.back().first < temp){
                int j = stk.back().second;
                temperatures[j] = (i - j);
                stk.pop_back();
            }
            stk.push_back({temp, i});
        }   

        while(stk.size()){
            int j = stk.back().second; 
            temperatures[j] = 0;
            stk.pop_back();
        }
        return temperatures;
    }
};
