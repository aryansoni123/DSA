class Solution {
public:

    int f(int i, int j, vector<int> &prices, vector<vector<int>> &dp){

        int n = prices.size();

        if (i == n) return 0;

        // if (j==n-1) return prices[j] - prices[i];

        if (dp[i][j] != -1) return dp[i][j];

        int pick = 0, not_pick = 0;

        if (j) dp[i][j] = max(-prices[i] + f(i+1, 0, prices, dp), f(i+1, 1, prices, dp));
        else dp[i][j] = max(prices[i] + f(i+1, 1, prices, dp), f(i+1, 0, prices, dp));

        // pick = prices[j] - prices[i] + f(i+1, j+1, prices, dp);
        // not_pick = f(i, j+1, prices, dp);

        return dp[i][j];
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // vector<vector<int>> dp(n, vector<int>(2, -1));
        vector<int> front(2, 0);

        for (int i = n-1; i>=0; i--){
            
            vector<int> prev(2, 0);

            prev[1] = max(-prices[i] + front[0], front[1]);
            prev[0] = max(prices[i] + front[1], front[0]);

            front = prev;

        }

        return front[1];

        // int a = f(0, 1, prices, dp);

        // for(auto &row: dp){
        //     for (auto i: row){
        //         cout<<i<<' ';
        //     }
        //     cout<<endl;
        // }

        // return a;


    }
};