class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1; int hi = (int)1e9; 

        while(lo <= hi){
                    bool flag = false; 
            int mid = (lo + hi) >> 1; 
            cout << "Lo: " << lo << endl;
            cout << "Hi: " << hi << endl;
            cout << mid << endl;
            int i = 0;
            int t =  0;
            int n = piles.size();
            while(i < n){
                if (piles[i] % mid){
                    t++;
                }
                t += piles[i]/mid;

                if (n -i-1+t>h){
                    // cout << "Happened at " << mid << endl;
                    flag = true; 
                    break;
                }
                i++;


            }
            cout << "Flag: " << (int) flag << endl;
            cout << "T: " << t << endl;
            if (flag){
                lo = mid+1;
            }
            else if (t > h){
                cout << "T: " << t << endl;lo = mid+1;
            } 
            else hi = mid-1;
        }
        return lo;
    }
};
