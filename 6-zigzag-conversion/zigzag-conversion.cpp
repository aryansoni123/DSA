class Solution {
public:
    string convert(string s, int numRows) {

        int n = numRows+1;
        int j = 0;
        int k = 0;
        int m = s.size();

        if (numRows==1) return s;

        vector<vector<char>> dp(numRows+1, vector<char>(m, ' '));

        for(int i = 0; i<n; i++){
            if (k==m) break;
            if (i==n-1){
                i--;
                while (i!=0 && k<m){
                    i--;
                    j++;
                    dp[i][j] = s[k];
                    k++;
                }
                // continue;
            } else{
                dp[i][j] = s[k];
                k++;

            }
        }

        string a = "";

        for(auto &row: dp){
            for(auto it: row){
                // cout<<it<<' ';
                if(it!=' ') a+=it;
            }
            // cout<<endl;
        }

        return a;
    }
};