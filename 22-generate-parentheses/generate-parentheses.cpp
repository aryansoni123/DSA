class Solution {
public:

    void f(int i, int n, int cnt, string &tmp, vector<string> &ans){
        if(i==0){

            if(cnt == 0){
                // cout<<'1';
                ans.push_back(tmp);
            }

            return;
        }

        if(cnt>n) return;

        if(cnt>=0){
            tmp+='(';
            f(i-1, n, cnt+1, tmp, ans);
            tmp.pop_back();
        }

        if(cnt>0){
            tmp+=')';
            f(i-1, n, cnt-1, tmp, ans);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string tmp = "";

        f(2*n, n, 0, tmp, ans);



        return ans;
    }
};