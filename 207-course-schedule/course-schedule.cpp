class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);

        for(auto x: prerequisites){
            indeg[x[1]]++;
            adj[x[0]].push_back(x[1]);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        for(int i = 0; i<n; i++){
            if(indeg[i] == 0) q.push(i);
        }

        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            vis[node] = 1;
            cnt++;

            for(auto x: adj[node]){
                indeg[x]--;
                if(!indeg[x] && !vis[x]) q.push(x);
            }
        }

        return cnt == n;
    }
};