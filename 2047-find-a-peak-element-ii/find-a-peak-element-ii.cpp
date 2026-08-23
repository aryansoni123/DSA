class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // int mx = 0;

        int l = 0, h = m-1;

        vector<int> ind(2, 0);

        while(l<=h){
            int mid = l + (h-l)/2;
            int mx = 0;
            for(int j = 0; j<n; j++){
                if(mat[j][mid] > mx){
                    ind = {j, mid};
                    mx = mat[j][mid];
                }
            }

            cout<<l<<h<<mid<<endl;

            cout<<mx<<endl;

            int left = (mid-1 >= 0) ? mat[ind[0]][mid-1] : -1;
            int right = (mid+1 < m) ? mat[ind[0]][mid+1] : -1;
            // int right = mid+1;

            if(right < mx && left<mx) return ind;
            else if(left>mx){
                h = mid - 1;
            } else{
                l = mid + 1;
            }
        }

        return {-1, -1};
    }
};