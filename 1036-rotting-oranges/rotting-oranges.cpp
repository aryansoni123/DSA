class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int rotten = 0;

        int n = grid.size();      
        int m = grid[0].size();      

        queue<vector<int>> q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
                
                if(grid[i][j] == 1) fresh++;
            }
        }

        int t = 0;

        while(!q.empty()){
            vector<int> node = q.front();
            q.pop();

            int r = node[0];
            int c = node[1];
            t = node[2];

            // if(t>ans) continue;

            // if(rotten == fresh) return t;

            int dr[4] = {0,1,0,-1};
            int dc[4] = {1,0,-1,0};

            for(int k = 0; k<4; k++){
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr>=0 &&nr<n && nc>=0 &&nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    q.push({nr, nc, t+1});
                    vis[nr][nc] = 1;
                    rotten++;   
                }
            }

        }

        if(rotten!=fresh) return -1;

        return t;

    }
};