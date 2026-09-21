class Solution {
public:

    vector<long long> resultArray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<vector<double>> dp(n+1, vector<double>(k, 0));
        vector<long long>ans(k, 0);

        for(int i = 0; i<n; i++){
            dp[i][nums[i]%k]++;

            if(i>0){
                for(int r = 0; r<k; r++){
                    dp[i][r*(nums[i]%k)%k] += dp[i-1][r];
                }
            }

            for(int r = 0; r<k; r++){
                ans[r]+=dp[i][r];
            }
        }

        return ans;
    }
};