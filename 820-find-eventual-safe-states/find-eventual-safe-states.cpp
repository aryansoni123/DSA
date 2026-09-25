class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);

        vector<int> indeg(n);

        for(int i = 0; i<n; i++){
            for(auto x: graph[i]){
                adj[x].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;

        vector<int> sf(n, 0);

        for(int i = 0; i<n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            sf[node] = 1;

            for(auto x: adj[node]){
                indeg[x]--;
                if(indeg[x] == 0) q.push(x);
            }
        }

        for(int i = 0; i<n; i++){
            if(sf[i]) topo.push_back(i);
        }

        return topo;
    }
};