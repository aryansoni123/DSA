class Solution {
public:

    int dr[2] = {0,1};
    int dc[2] = {1,0};

    bool dfs(int r, int c, int cnt, vector<vector<char>>& grid, vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();

        if(cnt<0) return false;
        
        if(r == n-1 && c == m-1){
            if(grid[r][c] == ')') return cnt == 0;
            else return false;
        }

        if(dp[r][c][cnt] != -1) return dp[r][c][cnt];

        for(int k = 0; k<2; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr>=0 && nr<n && nc>=0 && nc<m){
                int ncnt = cnt;

                if(grid[nr][nc] == '(') ncnt++;
                else ncnt--;
                
                if (dfs(nr, nc, ncnt, grid, dp)) return true;

            }
        }


        return dp[r][c][cnt] = false;
        
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n+m+1, -1)));

        int cnt = 0;
        
        if(grid[0][0] == '(') cnt++;
        else cnt--;

        return dfs(0, 0, cnt, grid, dp);
    }
};