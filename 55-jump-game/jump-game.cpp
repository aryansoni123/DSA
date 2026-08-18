class Solution {
public:

    bool f(int i, vector<int> &nums, vector<int> &dp){
        int n = nums.size();

        if(i>=n) return false;

        if(i == n-1) return true;

        if(dp[i] != -1) return dp[i];

        for(int j = 1; j<=nums[i]; j++){
            if(f(i + j, nums, dp)) return dp[i] = true;
        }

        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        int far = 0;

        for(int i = 0; i<n; i++){

            if(i>far) return false;

            far = max(far, i + nums[i]);

            if(far>=n-1) return true;
        }

        return false;

        // return f(0, nums, dp);
    }
};