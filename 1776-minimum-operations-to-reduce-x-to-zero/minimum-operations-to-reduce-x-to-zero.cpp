class Solution {
public:

    int f(int l, int r, int x, vector<int>&nums, vector<vector<vector<int>>> &dp){
        if(x == 0) return 0;

        if(l>r) return INT_MAX;

        if(dp[l][r][x]!=-1) return dp[l][r][x];

        int left = INT_MAX, right = INT_MAX;

        if(nums[l]<=x) left = f(l+1, r, x - nums[l], nums, dp); 
        if(nums[r]<=x) right = f(l, r-1, x - nums[r], nums, dp); 

        if(left != INT_MAX) left++;
        if(right != INT_MAX) right++;

        return dp[l][r][x] = min(left, right);

    }

    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(x+1, -1)));

        // int res = f(0, n-1, x, nums, dp);

        // return res == INT_MAX ? -1 : res;

        int req = 0;

        for(auto x: nums) req+=x;

        req-=x;

        // cout<<req;

        int l = 0, r = 0;

        int ans = -1;

        int sum = 0;

        while(r<n){
            req-=nums[r];

            while(l<=r && req<0){
                req+=nums[l];
                l++;
                // ans++;
            }

            if(req == 0) ans = max(ans, r-l+1);
            r++;
            // ans--;
        }

        // cout<<endl; 
        // cout<<ans;
        // cout<<endl;
        // cout<<l<<' ';
        // cout<<r;


        // if(req!=0) return -1;

        return ans == -1 ? ans : n - ans;
    }
};