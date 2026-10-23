class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited){
        visited[node]= true; 

        for(auto &v: adj[node]){
            if (not visited[v]){
                dfs(v, adj, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(); 
        int cols = grid[0].size(); 
        vector<vector<int>> graph(rows * cols, vector<int>());
        vector<bool> visited(rows * cols);
        for(int node =  0; node < rows * cols; node++){
            int node_row = node/cols; 
            int node_col = node % cols;
            if (grid[node_row][node_col] == '1'){
                if (node_row < rows-1 and grid[node_row+1][node_col] == '1'){
                    // we can connect down
                    graph[node].push_back(node + cols);
                    graph[node + cols].push_back(node);
                }

                if (node_col < cols-1 and grid[node_row][node_col+1] == '1'){
                    // we can connect right 
                    graph[node].push_back(node+1); 
                    graph[node+1].push_back(node);

                }
            }

        }

        int count = 0; 

        for(int node = 0; node < rows*cols; node++){
            if (grid[node/cols][node % cols] == '1' and !visited[node]){
                dfs(node, graph, visited); 
                count++;
            }
        }
        return count;
    }
};
