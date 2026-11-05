class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;

        int n = arr1.size();
        int m = arr2.size();

        for(int i = 0; i<n; i++){
            int f = 0;
            for(int j = 0; j<m; j++){
                int diff = abs(arr1[i] - arr2[j]);

                if(diff<=d){
                    f = 1;
                    break;
                }
            }
            if(!f) ans++;
        }

        return ans;
    }
};