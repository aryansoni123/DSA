class Solution {
public:

    int f(int i, int j, int turn, vector<int> &piles, vector<vector<vector<int>>> &dp){
        if (i>j) return 0;

        if(dp[i][j][turn] != -1) return dp[i][j][turn];

        if (turn){
            return dp[i][j][1] = max(
                piles[i] + f(i + 1, j, 0, piles, dp),
                piles[j] + f(i, j - 1, 0, piles, dp)
            );
        } else{
            return dp[i][j][0] = min(
                -piles[i] + f(i + 1, j, 1, piles, dp),
                -piles[j] + f(i, j - 1, 1, piles, dp)
            );
        }
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

        int a = f(0, n-1, 1, piles, dp);

        // cout<<a;

        return a>0;
    }
};