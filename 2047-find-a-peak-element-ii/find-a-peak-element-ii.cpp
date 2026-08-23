class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int mx = 0;
        vector<int> ind(2, 0);

        for(int i = 0; i<n ; i++)
            for(int j = 0; j<m; j++){
                if(mat[i][j] > mx){
                    ind = {i, j};
                    mx = mat[i][j];
                }
            } 
            // mx = max(mx, x);

        return ind;
    }
};