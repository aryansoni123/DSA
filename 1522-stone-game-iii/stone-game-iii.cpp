class Solution {
public:

    int f(int i, vector<int> &nums, vector<int> &dp){
        if(i == nums.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int pick = 0, ans = INT_MIN;

        for(int k = i; k<i+3 && k<nums.size(); k++){
            pick += nums[k];
            ans = max(ans, pick - f(k+1, nums, dp));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // vector<int> dp(n, -1);
        vector<int> dp(3, 0);

        // int ans = f(0, stoneValue, dp);

        for(int i = n-1; i>=0; i--){
            int ans = INT_MIN, pick = 0;
            
            for(int k = i; k<i+3 && k<n; k++){
                pick+=stoneValue[k];
                ans = max(ans, pick - dp[k-i]);
            }
            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = ans;            
        }

        int ans = dp[0];

        if(ans>0) return "Alice";
        else if(ans<0) return "Bob";
        else return "Tie";
    }
};