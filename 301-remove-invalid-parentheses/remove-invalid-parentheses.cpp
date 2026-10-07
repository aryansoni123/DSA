class Solution {
public:

    int l = 0;

    void f(int i, int cnt, string& tmp, string &s, unordered_set<string> &ans){

        if(i == s.size()){
            // cout<<"a";
            if(cnt == 0){
                if(tmp.size()==l) ans.insert(tmp);
                else if(tmp.size() > l){
                    ans.clear();
                    ans.insert(tmp);
                    l = tmp.size();
                }
            } 

            return;
        }
        if(cnt>=0){
            int ncnt = cnt;
            tmp+=s[i];

            if(s[i] == '(') ncnt++;
            else if(s[i] == ')') ncnt--;

            f(i+1, ncnt, tmp, s, ans);

            tmp.pop_back();
        }

        if(s[i] == '(' || s[i] == ')'){
            f(i+1, cnt, tmp, s, ans);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;   

        string tmp = "";   

        f(0, 0, tmp, s, ans);

        vector<string> res;

        for(auto x: ans){
            res.push_back(x);
        }

        return res;
    }
};