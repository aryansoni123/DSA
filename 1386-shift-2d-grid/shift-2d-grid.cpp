class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        k = k%(m*n);

        cout<<k;

        if (!k) return grid;

        // int s = k/n;
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans[i][j] = grid[i][j];
            }
        }
        

        while(k){
            swap(ans, grid);
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if (i == n-1 && j == m-1) ans[0][0] = grid[i][j];
                    else if (j == m-1) ans[i+1][0] = grid[i][j];
                    else ans[i][j+1] = grid[i][j];
                }
            }
            k--;
        }

        return ans;
              
    }
};