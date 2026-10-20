class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(); 
        int c = matrix[0].size(); 

        if (matrix[0][0] > target or matrix[r-1][c-1] < target)  return false;

        int lo = 0; int hi = r-1; 
        while(lo <= hi){
            int mid = (lo +hi) >> 1; 
            int elem = matrix[mid][0];
            if (matrix[mid][0] == target){
                return true;
            }
            else if (elem < target){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }

        cout << lo << endl;

        auto it = lower_bound(matrix[lo-1].begin(), matrix[lo-1].end(), target); 
        if (it != matrix[lo-1].end() and *it == target){
            return true;
        }
        return false; 
    }
};
