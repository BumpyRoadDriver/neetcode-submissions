class KthLargest {
public:
    vector<int> nums;
    priority_queue<int, vector<int>, greater<int>> pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        this -> nums = nums; 
        this -> sz = k;
        for(auto num: nums){
            pq.push(num);
        }

        while(pq.size() > k){
            pq.pop();
        }

    }
    
    int add(int val) {
        nums.push_back(val); 
        if (pq.size() < sz){
            pq.push(val);
        }
        else if (val > pq.top()){
            pq.pop(); 
            pq.push(val);
        }
        return pq.top();
    }
};
