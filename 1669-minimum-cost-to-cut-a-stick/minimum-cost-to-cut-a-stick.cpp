class Solution {
public:

    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if (i>j) return 0;

        int mini = INT_MAX, cuts = 0;
        int cut = arr[j+1] - arr[i-1];

        if (dp[i][j] != -1) return dp[i][j];

        // if (i == 0) cut = arr[j+1];
        // else 
        

        for(int k = i; k<=j; k++){
            cuts = cut + f(i, k-1, arr, dp) + f(k+1, j, arr, dp);
            mini = min(cuts, mini);
        }

        return dp[i][j] = mini;


    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m,-1));
        // vector<vector<int>> dp(m, vector<int>(m,0));
        sort(cuts.begin(), cuts.end());

        return f(1, m-2, cuts, dp);

        // int cut, cutss, mini = 0;

        // for(int i = m-2; i>0; i--){
        //     for(int j = i; j<=m-2; j++){
        //         mini = INT_MAX;
        //         for(int k = i; k<=j; k++){
        //             // if (i == 0) cut = cuts[j+1];
        //             // else 
        //             cut = cuts[j+1] - cuts[i-1];

        //             cutss = cut + ((k==i) ? 0 : dp[i][k-1]) + ((k==j) ? 0 : dp[k+1][j]);
        //             mini = min(mini, cutss);
        //         }
        //         dp[i][j] = mini;

        //     }
        // }

        // return dp[1][m-2];
    }
};