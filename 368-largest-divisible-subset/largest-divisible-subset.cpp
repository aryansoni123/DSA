class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> hash(n, 1);

        int mx = 1, lis = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i<n; i++) hash[i] = i;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0 && 1 + dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    hash[i] = j;

                    if (dp[i]>mx){
                        mx = dp[i];
                        lis = i;
                    }
                }
            }
        }

        vector<int> ans;

        while (hash[lis] != lis){
            ans.push_back(nums[lis]);
            lis = hash[lis];
        }
        ans.push_back(nums[lis]);

        return ans;
    }
};