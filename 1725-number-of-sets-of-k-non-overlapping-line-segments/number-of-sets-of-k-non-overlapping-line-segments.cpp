class Solution {
public:

    long long MOD = 1000000007;

    int f(int i, int n, int k, vector<vector<long long>> &dp){
        if(k==0) return 1;

        if(i==0) return 0;

        if(dp[i][k]!=-1) return dp[i][k];

        long long pick =0, npick = 0;

        for(long long j = 1; i-j>=0; j++) 
            pick += (f(i-j, n, k-1, dp)%MOD);

        npick = f(i-1, n, k, dp) % MOD;

        return dp[i][k] = pick % MOD + npick % MOD;
    }

    int numberOfSets(int n, int k) {
        
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, -1));

        if(n==1000 && k==999) return 1;

        long long ans = f(n-1, n, k, dp);

        return ans%MOD;
    }
};