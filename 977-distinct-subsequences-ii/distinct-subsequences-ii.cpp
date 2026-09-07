class Solution {
public:

    // int f(int i, int ans, string s, vector<int> picked){
    //     int n = s.size();

    //     if(i == n){
    //         ans++;
    //     }
    // }

    long long MOD = 1000000007;

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<long long> dp(n+1, 0);        
        vector<int> last(26, -1);

        dp[0] = 1;

        for(int i = 0; i<n; i++){
            char ch = s[i];
            dp[i+1] = 2*dp[i]%MOD;

            if(last[ch-'a']!=-1){
                dp[i+1]-=dp[last[ch-'a']];
                dp[i+1] = (dp[i + 1] + MOD) % MOD;
            }

            dp[i+1]%=MOD;

            last[ch-'a'] = i;
        }

        return (dp[n]-1+MOD)%MOD;
    }
};