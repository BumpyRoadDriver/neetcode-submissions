class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk; 
        int n = temperatures.size(); 
        for(int i = 0; i < n; i++){
            int temp = temperatures[i]; 

            while(stk.size() and stk.top().first < temp){
                int j = stk.top().second;
                temperatures[j] = (i - j);
                stk.pop();
            }
            stk.push({temp, i});
        }   

        while(stk.size()){
            int j = stk.top().second; 
            temperatures[j] = 0;
            stk.pop();
        }
        return temperatures;
    }
};
