class Solution {
public:

    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        // int ans = 1;

        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0};

        // queue<pair<int, int>> q;

        // q.push({i,j});
        vis[i][j] = 1;

        // while(!q.empty()){
        //     auto [r, c] = q.front();
        //     q.pop();

        for(int k = 0; k<4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc] == '1'){
                // vis[nr][nc] = 1;
                // q.push({nr, nc});
                bfs(nr, nc, vis, grid);
                // ans++;
            }
        }
        // }

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    bfs(i,j, vis, grid);
                    ans++;
                }
            }
        }

        return ans;
    }
};