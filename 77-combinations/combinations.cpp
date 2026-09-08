class Solution {
public:

    void f(int i, int n, int k, vector<vector<int>> &ans, vector<int> &tmp){
        if(i>n){

            if(k==0){
                vector<int> t;
                for(auto x: tmp) t.push_back(x);
                ans.push_back(t);
            }

            return;
        }

        if(k){
            tmp.push_back(i);
            k--;
            f(i+1, n, k, ans, tmp);
            tmp.pop_back();
            k++;
        } 

        f(i+1, n, k, ans, tmp);

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;

        f(1, n, k, ans, tmp);

        return ans;
    }
};