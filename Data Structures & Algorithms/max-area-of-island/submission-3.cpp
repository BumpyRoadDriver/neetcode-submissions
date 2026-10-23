class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited, int &cur_ans){
        visited[row][col] = true; 
        int rows = grid.size(); 
        int cols = grid[0].size();
        cur_ans++;

        if (row + 1 < rows and grid[row+1][col]==1 and not visited[row+1][col]){
            dfs(row+1, col, grid, visited, cur_ans);
        }
        if (col +1 < cols and grid[row][col+1] == 1 and not visited[row][col+1]){
            dfs(row, col+1, grid, visited, cur_ans);
        }
        if (row-1 >= 0 and grid[row-1][col] == 1 and not visited[row-1][col]){
            dfs(row-1, col, grid, visited, cur_ans);
        }
        if (col-1 >= 0 and grid[row][col-1] == 1 and not visited[row][col-1]){
            dfs(row, col-1, grid, visited, cur_ans);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(); 
        int cols = grid[0].size(); int ans = 0;
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if (grid[row][col] == 1 and not visited[row][col]){
                    int cur_ans = 0; 
                    dfs(row, col, grid, visited, cur_ans);
                    ans = max(ans, cur_ans);
                }
            }
        }
        return ans;
    }
};
