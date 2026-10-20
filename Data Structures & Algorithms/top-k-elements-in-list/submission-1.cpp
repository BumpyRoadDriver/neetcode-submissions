class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>arr (2001);
        for(auto num: nums){
            arr[num+1000]++;
        }

        vector<pair<int,int>> tmp(nums.size());
        int j =0;
        for(int i  =0; i <= 2000; i++){
            if (arr[i]){
                tmp[j++]=  {arr[i], i-1000};
        
            }
        }

        sort(tmp.rbegin(), tmp.rend()); 

        
        vector<int> sol(k); 
        for(int i = 0; i <k ;i++){
            sol[i]= tmp[i].second;
        }
        return sol; 

        
        
    }
};
