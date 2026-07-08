class Solution {
public:

    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int pick = 0, not_pick = 0;        
        if (s[i] == t[j]){
            // vis[i][j] = 1;
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        }

        return dp[i][j] = f(i-1, j, s, t, dp);

    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        // vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        vector<double> prev(m+1, 0);

        // for(int i = 0; i<=n; i++){
        //     dp[i][0] = 1;
        // }

        prev[0] = 1;

        // dp[i][j] = 

        for (int i = 1; i<=n; i++){
            vector<double> curr(m+1, 0);
            curr[0] = 1;
            for(int j = 1; j<=m; j++){
                // dp[i][j] = (s[i-1] == t[j-1]) ? dp[i-1][j] + dp[i-1][j-1]: dp[i-1][j];
                curr[j] = (s[i-1] == t[j-1]) ? prev[j] + prev[j-1]: prev[j];
            }
            prev = curr;
        }

        // for (auto &row: dp){
        //     for(auto &it: row){
        //         cout<<it<<' ';
        //     }
        //     cout<<endl;
        // }

        // return dp[n][m];

        return (int)prev[m];

        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // return f(n-1, m-1, s, t, dp);

        // return 1;

    }
};