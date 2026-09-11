class Solution {
public:
    int ans = INT_MAX;
    int f(int i, vector<int> &nums, vector<int> &dp){
        int n = nums.size();

        // if(i>=n) return false;

        if(dp[i]!=-1) return dp[i];

        if(i==n-1){
            // ans = min(ans, cnt);
            return 0    ;
        }

        int val = INT_MAX;

        for(int j = nums[i]; j>=1; j--){
            if(i+j >= nums.size()) continue;
            int reach = f(i+j, nums, dp);
            if(reach!=INT_MAX) val = min(reach + 1, val);
        }

        ans = min(val, ans);

        return dp[i] = val;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        // int cnt = 0;

        return f(0, nums, dp);

        // return ans;
    }
};