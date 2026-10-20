class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 

        if (n == 1) return 0 ;
        int i = 0; 
        while(i < n and (not height[i])){i++;}
        int j = i+1;; 
        int ans = 0; 
        int cur =  0; 
        while(j < n){
            if (height[j] >= height[i]){
                ans += cur;
                i = j; 
                j = i+1;
                cur = 0;
            }
            else{
                cur += (-height[j] + height[i]);
                j++;
            }
        }

        if (i == n-1) return ans; 

                vector<int> smax(n-i+1); 
        for(int k = n-1; k >= i+1; k--){
            smax[k-i] = max(smax[k-i+1], height[k]);
        }
        int oi = i; 
        while(i+1 < n){
            int val = smax[i+1-oi];
            int k = i+1; 
            while(height[k] != val){
                ans += (val - height[k]);
                k++;
            }
            i = k; 

        }
        return ans;


    }
};
