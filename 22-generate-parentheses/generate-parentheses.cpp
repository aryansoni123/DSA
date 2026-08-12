class Solution {
public:

    int f(int i, int n, int cnt, string &temp, vector<string> &ans){
        if(i==0){
            if(cnt==0) ans.push_back(temp);
            return 0;
        };

        if(cnt<=n){
            temp.push_back('(');
            f(i-1, n, cnt+1, temp, ans);
            temp.pop_back();
        }

        if(cnt>0){
            temp.push_back(')');
            f(i-1, n, cnt-1, temp, ans);
            temp.pop_back();
        } 

        return 0;
    }

    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> ans;
        f(2*n, n, 0, temp, ans);

        return ans;
    }
};