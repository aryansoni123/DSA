class Solution {
public:
    int maxDepth(string s) {
        // stack<char> st;

        int cnt = 0, ans = 0;

        for(auto x: s){
            if(x == '(') cnt++;
            if(x == ')') cnt--;

            ans = max(ans, cnt);
        }

        return ans;
    }
};