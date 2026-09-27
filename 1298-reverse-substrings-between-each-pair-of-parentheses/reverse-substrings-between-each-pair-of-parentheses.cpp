class Solution {
public:

    // Not Even a hint

    pair<string, int> helper(int i, string &s){
        int n = s.size();

        string tmp = "";

        while(i<n && s[i]!=')'){
            if(s[i] == '('){
                auto [val, j] = helper(++i, s);
                i = j;
                tmp+=val;
            } else{
                if(i<n && s[i]!=')') tmp+=s[i];
                i++;
            }
        }


        reverse(tmp.begin(), tmp.end());

        return {tmp, ++i};
    }

    string reverseParentheses(string s) {

        int n = s.size();
        int i = 0;

        string ans = "";

        while(i<n){
            if(s[i] == '('){
                auto [val, j] = helper(++i, s);
                ans+=val;
                i = j;
            } else{
                ans+=s[i];
                i++;
            }
        }
        
        return ans;
    }
};