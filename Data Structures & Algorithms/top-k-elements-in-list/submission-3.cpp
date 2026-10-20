class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> cnt(2001); 
        for(auto num: nums){
            cnt[num+1000]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i <= 2000; i++){
            int num =  i;
            if( cnt[num])
            pq.push({cnt[num], num-1000}); 

        }
        vector<int> sol(k); 
        int j = 0;
        while(k--){
            sol[j++] = pq.top().second; 
            pq.pop();
        }
        return sol; 

        
        
    }
};
