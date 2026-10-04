class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        int open = 0;
        int close = 0;

        int ans = 0;

        for(int i = 0; i<n; i++){
            if(s[i] == '(') open++;
            else close++;

            if(close>open){
                close = 0;
                open = 0;
            }

            if(open == close){
                ans = max(ans, open + close);
            }
        }

        int res2 = 0;

        open = 0;
        close = 0;

        for(int i = n-1; i>=0; i--){
            if(s[i] == ')') open++;
            else close++;

            if(close>open){
                close = 0;
                open = 0;
            }

            if(open == close){
                res2 = max(res2, open + close);
            }
        }

        return max(res2, ans);


        // if(open>close) ans = 2*close;

        // return ans;
    }
};