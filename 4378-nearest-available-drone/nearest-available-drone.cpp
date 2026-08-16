class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int cnt = INT_MAX;

        for(int i = 0; i<drones.size(); i++){
            vector<int> it = drones[i];
            int x = it[0];
            int y = it[1];

            int x1 = target[0];
            int y1 = target[1];

            int dist = abs(x-x1) + abs(y-y1);

            if(dist<=it[2]){
                if(dist<cnt){
                    ans = i;
                    cnt = dist;
                }
            }
        }

        return ans;
        
    }
};