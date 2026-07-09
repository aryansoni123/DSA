class Solution {
public:
    int find(int x, vector<int> &parent){
        if (parent[x] != x) parent[x] = find(parent[x], parent);
        return parent[x];

    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n, 0);

        for(int i = 0; i<n; i++) parent[i] = i;

        int pu, pv;

        for(int i = 1; i<n; i++){
            pu = find(i-1, parent);
            pv = find(i, parent);

            if (nums[i] - nums[i-1] <= maxDiff) parent[pu] = parent[pv];
        }

        int u, v;

        vector<bool> ans;

        for(auto &it: queries){
            u = it[0];
            v = it[1];

            if (find(u, parent) == find(v, parent)) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};