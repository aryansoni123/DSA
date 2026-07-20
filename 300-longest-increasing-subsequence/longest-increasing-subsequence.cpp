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

        // vector<int> dp(n, 1);
        // int mx = 1;

        // for(int i = 0; i<n; i++){
        //     for (int j = 0; j<i; j++){
        //         if(nums[i]>nums[j] && 1+dp[j] > dp[i]){
        //             dp[i] = 1 + dp[j];
        //             mx = max(mx, dp[i]);
        //         }
        //     }
        // }

        // return mx;

        vector<int> tmp;
        

        for(int i = 0; i<n; i++){
            if(!tmp.size() || tmp.back()<nums[i]) tmp.push_back(nums[i]);

            else{
                auto ind = lower_bound(tmp.begin(), tmp.end(), nums[i]);
                // tmp[ind] = nums[i];
                *ind = nums[i];
            }
        }
        
        return tmp.size();

        // vector<int> front(n+1, 0);
        // vector<int> curr(n+1, 0);
        // int ans = INT_MIN;


        // for(int i =  n-1; i>=0; i--){
        //     for(int j = n-1; j>=-1; j--){
                
        //         // int pick = 0, not_pick = 0;

        //         // if(j == -1 || nums[j] < nums[i]) pick = 1 + front[i+1];
        //         // if (j!=-1) not_pick = front[j+1];
                
        //         // curr[j+1] = max(pick, not_pick);
        //         // ans = max(ans, curr[j+1]);


        //     }
            
        //     swap(curr, front);
        // }

        // // return front[n];
        // return ans;



        // return f(0, -1, nums, dp);
        // return f(0, INT_MIN, nums);
        
    }
};