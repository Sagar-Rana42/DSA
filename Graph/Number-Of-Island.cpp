class Solution {
    public:
        void BFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
    
            // Directions for moving up, down, left, and right
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, -1, 1};
    
            while (!q.empty()) {
                auto node = q.front();
                q.pop();
    
                int x = node.first;
                int y = node.second;
    
                // Check all 4 possible directions
                for (int k = 0; k < 4; k++) {
                    int newX = x + dx[k];
                    int newY = y + dy[k];
                    
                    // Validate the new position
                    if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() &&
                        !visited[newX][newY] && grid[newX][newY] == '1') {
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
        }
    
        int numIslands(vector<vector<char>>& grid) {
            int n = grid.size(); // Rows
            int m = grid[0].size(); // Columns
            
            // Create a 2D visited array initialized to false
            vector<vector<bool>> visited(n, vector<bool>(m, false));
    
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '1' && !visited[i][j]) {
                        BFS(grid, visited, i, j);
                        ans++;
                    }
                }
            }
            return ans;
        }
    };
    