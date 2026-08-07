class Solution {
public:

    int f(int i, vector<int> &nums, vector<int>& dp){
        int n = nums.size();

        if(i == n-1) return 0;
        if(i>=n) return pow(10,9);

        if(dp[i]!=-1) return dp[i];

        int temp = 0, ans = pow(10,9);

        for (int j = 1; j <= nums[i] && i + j < n; j++) {
            int temp = f(i + j, nums, dp);

            if (temp != INT_MAX)
                ans = min(ans, 1 + temp);
        }

        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return f(0, nums, dp);
        
    }
};