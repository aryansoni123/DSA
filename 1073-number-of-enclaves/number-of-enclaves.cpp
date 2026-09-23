class Solution {
public:

    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};

    int bfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1;

        queue<pair<int,int>> q;

        q.push({i, j});
        vis[i][j] = 1;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k<4; k++){
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]){
                    ans++;
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        return ans;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int tot = 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                tot+=grid[i][j];
            }
        }

        int sub = 0;

        for(int i = 0; i<n; i++){
            if(grid[i][0] && !vis[i][0])
                sub += bfs(i, 0, vis, grid);

            if(grid[i][m-1] && !vis[i][m-1])
                sub += bfs(i, m-1, vis, grid);
        }

        for(int i = 0; i<m; i++){
            if(grid[0][i] && !vis[0][i])
                sub += bfs(0, i, vis, grid);
            if(grid[n-1][i] && !vis[n-1][i])
                sub += bfs(n-1, i, vis, grid);
        }

        // cout<<tot;

        return tot-sub;
    }
};