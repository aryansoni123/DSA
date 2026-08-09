class Solution {
public:

    int f(int i, int m, vector<int>& arr, vector<vector<int>> &dp){
        int n = arr.size();
        if (i >= n) return 0;

        if(dp[i][m]!=-1) return dp[i][m];

        int pick = 0, ans = INT_MIN;

        for(int j = 1; j+i<=n && j<=2*m; j++){
            pick += arr[j+i-1];
            ans = max(ans, pick - f(j + i, max(m, j), arr, dp));
        }
        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int sum = 0;
        int n = piles.size();

        for(auto x: piles) sum+=x;

        vector<vector<int>> dp(n, vector<int>(2 * n, -1));

        int diff = f(0, 1, piles, dp);

        return (sum+diff)/2;
    }
};