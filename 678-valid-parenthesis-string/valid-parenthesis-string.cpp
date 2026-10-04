class Solution {
public:

    int f(int i, int cnt, string &s, vector<vector<int>> &dp){
        int n = s.size();
        if(i==n){
            return cnt == 0;
        }

        if(cnt<0) return false;

        if(dp[i][cnt+100]!=-1) return dp[i][cnt+100];

        int c1 = false;
        int c2 = false;
        int c3 = false;

        if(s[i] == '*'){
            c1 = f(i+1, cnt+1, s, dp);
            c2 = f(i+1, cnt, s, dp);
            c3 = f(i+1, cnt-1, s, dp);
        } else{
            if(s[i] == '('){
                return dp[i][cnt+100] = f(i+1, cnt+1, s, dp);
            } else{
                return dp[i][cnt+100] = f(i+1, cnt-1, s, dp);
            }
        }

        return dp[i][cnt+100] = c1 | c2 | c3;
    }

    bool checkValidString(string s) {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(201, -1));

        return f(0, 0, s, dp);
    }
};