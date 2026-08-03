class Solution {
public:

    int f(int i, vector<int> &nums, vector<int> &dp){
        if(i == nums.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int pick = 0, ans = INT_MIN;

        // if (turn){
            for(int k = i; k<i+3 && k<nums.size(); k++){
                pick += nums[k];
                ans = max(ans, pick - f(k+1, nums, dp));
            }
        // }

        return dp[i] = ans;
        // else{
        //     for(int k = i; k<i+3 && k<nums.size(); k++){
        //         pick += nums[k];
        //         ans = max(ans, take - f(i+k, 0, nums));
        //     }
        // }
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n, -1);

        int ans = f(0, stoneValue, dp);


        if(ans>0) return "Alice";
        else if(ans<0) return "Bob";
        else return "Tie";
    }
};