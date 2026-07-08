class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int ans = 0;
        int x = 0, y = 0;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if (s[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                if (dp[i][j]>ans && i - dp[i][j] == n - j) {
                    ans = dp[i][j];
                    x = i;
                }
            }
        }

        // int i = n;
        // int j = n;
        // cout<<x<<ans<<endl;
        string a = s.substr(x-ans, ans);

        // while(x>0 || y>0){
        //     a+=s[x-1];
        //     x--;
        //     y--;
        // }

        // for(auto &row: dp){
        //     for(auto &it: row){
        //         cout<<it<<' ';
        //     }
        //     cout<<endl;
        // }

        return a;
        
    }
};