class Solution {
public:

    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
    // int f(int i, int j, vector<int> &nums){
        int n = nums.size();

        if (i==n) return 0;

        if (dp[i][j+1]!=-1) return dp[i][j+1];

        int pick = 0, not_pick = 0;

        if(j == -1 || nums[j] < nums[i]) pick = 1 + f(i+1, i, nums, dp);

        // if (j==0 && i==0) pick = 1 + f(i+1, i, nums, dp);
        
        not_pick = f(i+1, j, nums, dp);

        return dp[i][j+1] = max(pick, not_pick);
        // return max(pick, not_pick);
    }

    int lengthOfLIS(vector<int>& nums) {

        // int max1 = INT_MIN;
        int n = nums.size();
        // nums.push_back(INT_MIN);

        // for() max1 = max(max1, it);

        // vector<vector<int>> dp(n, vector<int>(n+1, -1));

        vector<int> front(n+1, 0);
        vector<int> curr(n+1, 0);
        int ans = INT_MIN;

        for(int i =  n-1; i>=0; i--){
            for(int j = n-1; j>=-1; j--){
                
                int pick = 0, not_pick = 0;

                if(j == -1 || nums[j] < nums[i]) pick = 1 + front[i+1];
                not_pick = front[j+1];
                
                curr[j+1] = max(pick, not_pick);
                ans = max(ans, curr[j+1]);
            }
            swap(curr, front);
        }

        return ans;



        // return f(0, -1, nums, dp);
        // return f(0, INT_MIN, nums);
        
    }
};