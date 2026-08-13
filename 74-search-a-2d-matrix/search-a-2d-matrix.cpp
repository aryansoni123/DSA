class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0, high = n-1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                int l = 0, h = m-1;

                while(l<=h){
                    int cen = l+(h-l)/2;

                    if(matrix[mid][cen] == target) return true;
                    else if(matrix[mid][cen]>target) h = cen -1;
                    else l = cen + 1;
                }

                return false;
            }

            else if(matrix[mid][0]>target){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }

        return false;
    }
};