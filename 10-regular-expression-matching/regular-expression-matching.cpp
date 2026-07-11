class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();
        
        vector<bool> prev(m+1, false);
        vector<bool> curr(m+1, false);

        prev[0] = true;

        for (int j = 2; j <= m; j++) {
            if (p[j-1] == '*')
                prev[j] = prev[j-2];
        }

        for (int i = 1; i<=n; i++){
            curr[0] = false;
            for (int j = 1; j<=m; j++){
                bool match = false, star = false, star1 = false;

                if (s[i-1] == p[j-1] || p[j-1] == '.') match = prev[j-1];

                if (p[j-1] == '*') {
                    if (j>=2) star = curr[j-2];

                    if (j>=2 && (s[i-1] == p[j-2] || p[j-2] == '.')) star1 = prev[j] || curr[j-2];
                }

                curr[j] = match || star || star1;

            }
            prev = curr;
        }
        return prev[m];
    }
};