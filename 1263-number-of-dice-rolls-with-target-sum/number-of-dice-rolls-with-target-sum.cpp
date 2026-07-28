class Solution {
public:

    int MOD = pow(10, 9) + 7;

    int f(int n, int target, int k, vector<vector<int>> &dp){
        // int k = arr.size();
        
        // if(target == 0) return 1;

        if(n==0){
            return target == 0;
        }

        if(target<0) return 0; 

        if(dp[n][target] != -1) return dp[n][target];

        long long ans = 0;

        for(int l = 1; l<=k; l++){
            ans+=f(n-1, target - l, k, dp) % MOD;
        }

        return dp[n][target] = ans % MOD;


        // int p = 0, np = 0;

        // if(arr[i]){
        //     arr[i]--;
        //     p +=f(i, target - (i + 1), arr);
        //     arr[i]++;
        // }
        // np +=f(i+1, target, arr);

        // return np+p;


    }

    int numRollsToTarget(int n, int k, int target) {
        // vector<int> arr(k, n);

        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

        return f(n, target, k, dp);

    }
};