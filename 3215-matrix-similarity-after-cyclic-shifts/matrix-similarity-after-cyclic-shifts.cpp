class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        if(k%m == 0) return true;

        k = k%m;

        for(int i = 0; i<n; i++){
            vector<int> row;
            for(auto x: mat[i]){
                row.push_back(x);
            }

            if(i%2){
                reverse(mat[i].begin(), mat[i].begin()+m-k);
                reverse(mat[i].begin()+m-k, mat[i].end());

                reverse(mat[i].begin(), mat[i].end());
            }
            else{
                reverse(mat[i].begin(), mat[i].begin()+k);
                reverse(mat[i].begin()+k, mat[i].end());

                reverse(mat[i].begin(), mat[i].end());
            }

            for(int j = 0; j<m; j++){
                if(mat[i][j]!=row[j]) return false;
            }

        }

        return true;

        /* 
        1, 2, 3, 4, 5

        2,1,5,4,3

        3,4,5,1,2

        left = 0-k k+1 - m
        right = 0-m-k m-k+1 - m
        
        */

    }
};