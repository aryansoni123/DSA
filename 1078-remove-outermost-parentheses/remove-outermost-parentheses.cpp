class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;

        string ans = "";

        for(auto x: s){
            if(x == ')') cnt--;
            if(cnt == 0){
                if(x == '(') cnt++; 
            } else{
                if(x == '(') cnt++; 
                ans+=x;
            }
        }

        return ans;
    }
};