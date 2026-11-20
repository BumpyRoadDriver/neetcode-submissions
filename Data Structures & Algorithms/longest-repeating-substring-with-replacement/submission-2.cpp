class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(); 
        if (n < 2) return n; 

        int ans = 1; 
        // try every possible character with two pointers
        for(char c = 'A'; c <= 'Z'; c++){
            
            for(int i= 0; i <= 0; i++){
                int mistakes =k; 
                int l = i; 
                int r =i;
                int cur_ans = 0; 
                queue<int> mistake_index;

                while(r < n){
                    if (s[r] != c){
                        mistake_index.push(r); 

                        if (mistakes){
                            mistakes--;
                            ans = max(ans, r-l+1); 
                            
                        }
                        else{
                            l = mistake_index.front()+1; 
                            mistake_index.pop();
                            ans = max(ans, r-l+1);
                            
                        }
                        
                    }
                    else{
                        ans = max(ans, r -l + 1);
                        
                    }
                    r++;
                }
                
            }
        }
        return ans;
    }
};
