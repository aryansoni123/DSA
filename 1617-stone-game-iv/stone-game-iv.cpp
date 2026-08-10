class Solution {
public:

    int f(int n, vector<int> &dp){

        // if(n==0) return false;

        if(dp[n]!= -1) return dp[n];

        for (int i = sqrt(n); i>=1; i--){
            if(!f(n-i*i, dp)){
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {

        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};