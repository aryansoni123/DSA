class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};

        vector<vector<int>> vis(n, vector<int>(m, -1));

        queue<pair<int, int>> q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            // int r = node[0];
            // int c = node[1];
            // int d = node[2];


            for(int i = 0; i<4; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==-1){
                    vis[nr][nc] = vis[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return vis;
    }
};