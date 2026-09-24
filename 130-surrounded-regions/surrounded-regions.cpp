class Solution {
public:

    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};

    void dfs(int r, int c, vector<vector<int>> &vis){
        int n = vis.size();
        int m = vis[0].size();
        vis[r][c] = 2;

        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                dfs(nr, nc, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == 'X'){
                    vis[i][j] = 1;
                }
            }
        }

        for(int i = 0; i<n; i++){
            if(vis[i][0] == 0) dfs(i, 0, vis);
            if(vis[i][m-1] == 0) dfs(i, m-1, vis);
        }

        for(int i = 0; i<m; i++){
            if(vis[0][i] == 0) dfs(0, i, vis);
            if(vis[n-1][i] == 0) dfs(n-1, i, vis);
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 0) 
                    board[i][j] = 'X';
                // continue;

            }
        }

        // return board;
    }
};