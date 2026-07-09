class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> front1(2, 0);
        vector<int> front2(2, 0);
        
        int n = prices.size();

        // vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for(int i = n-1; i>=0; i--){
            vector<int> curr(2, 0);

            // dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
            // dp[i][0] = max(prices[i] + dp[i+2][1], dp[i+1][0]);
        
            curr[1] = max(-prices[i] + front1[0], front1[1]);
            curr[0] = max(prices[i] + front2[1], front1[0]);

            front2 = front1;
            front1 = curr;
        }

        return front1[1];

    }
};