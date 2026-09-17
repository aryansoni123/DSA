class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int i = 0, j = 0;
        int n = arr.size();

        int minl = INT_MAX;
        int l = INT_MAX;
        int ans = INT_MAX;

        int sum = 0;
        vector<int> dp(n, INT_MAX);

        while(j<n){
            sum += arr[j];

            while(i<j && sum > target){
                sum -= arr[i++];
            }

            if(sum == target){
                l = j-i+1;
                
                if(i>0 && dp[i-1]!=INT_MAX){
                    ans = min(ans, dp[i-1] + l);
                }

                minl = min(l, minl);
                
            }

            dp[j] = minl;
            j++;
        }



        return ans!=INT_MAX ? ans : -1;

        // return 1;
    }
};