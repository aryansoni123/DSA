class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> ndp(n, 1);

        int mx = 1, cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if (nums[i]>nums[j] && 1+dp[j]>=dp[i]){
                    if (dp[i] < 1+dp[j]) ndp[i] = ndp[j];
                    else ndp[i]+=ndp[j];

                    dp[i] = 1 + dp[j];
                    mx = max(mx, dp[i]);

                    // if(dp[i]>mx){
                    //     mx = dp[i];
                    //     // cnt = i;
                    // } else if(dp[i] == mx) cnt++;
                }
            }
        }

        int ans = 0;

        cout<<mx;

        for(int i = 0; i<n; i++){
            if (dp[i] == mx){
                ans+=ndp[i];
            }
        }

        return ans;

        // return n;
    }
};