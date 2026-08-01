class Solution {
public:

    int f(int i, int j, int turn, vector<int>&nums, vector<vector<vector<int>>> &dp){
        if (i>j) return 0;

        int pf = 0, pl = 0;

        if (dp[i][j][turn] != -1) return dp[i][j][turn];

        if(turn){
            pf = nums[i] + f(i + 1, j , 0, nums, dp);
            pl = nums[j] + f(i, j-1, 0, nums, dp);

            return dp[i][j][1] = max(pf, pl);

        } else {
            pf = -nums[i] + f(i + 1, j , 1, nums, dp);
            pl = -nums[j] + f(i, j-1, 1, nums, dp);
            
            return dp[i][j][0] = min(pf, pl);
        }

        // return max(pf, pl);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

        return f(0, n-1, 1, nums, dp)>=0;
    }
};