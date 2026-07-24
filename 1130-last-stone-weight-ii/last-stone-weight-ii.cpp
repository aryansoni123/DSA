class Solution {
public:

    int f(int i, int target, vector<int> &nums, vector<vector<int>> &dp){
        int n = nums.size();

        if(i==n) return abs(target);
        // if(target<=0) return INT_MAX;

        if (dp[i][target + 3000]!=-1) return dp[i][target + 3000];

        int pick = 0, not_pick = 0;

        pick = f(i+1, target - nums[i], nums, dp);
        not_pick = f(i+1, target + nums[i], nums, dp);

        return dp[i][target + 3000] = min(pick, not_pick);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        // for(int i = 1; i<n; i++){
        //     for(int j = 1; )
        // }

        // int tot = 0;

        vector<vector<int>> dp(n+1, vector<int>(20001, -1));
        vector<int> nums;

        for(auto x: stones){
            // tot+=x;
            nums.push_back(x);
        }

        return f(0, 0, nums, dp);
    }
};