class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;

        vector<vector<int>> ans = {{1}, {1,1}};

        if(n == 1) return {{1}};
        if(n == 2) return ans;

        n-=2;
        int idx = 1;

        while(n>0){
            vector<int> curr;
            curr.push_back(1);

            for(int i = 0; i<ans[idx].size()-1; i++){
                curr.push_back(ans[idx][i] + ans[idx][i+1]);
            }

            curr.push_back(1);

            ans.push_back(curr);
            n--;
            idx++;
        }

        return ans;
    }
};