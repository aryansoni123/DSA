class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<vector<int>> adj(n);
        vector<int> indeg(n);

        for(auto x: prerequisites){
            adj[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }

        queue<int> q;

        for(int i = 0; i<n; i++)
            if(indeg[i] == 0) q.push(i);

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto x: adj[node]){
                indeg[x]--;
                if(!indeg[x]) q.push(x);
            }
        }

        if(topo.size() == n) return topo;

        return {};
    }
};