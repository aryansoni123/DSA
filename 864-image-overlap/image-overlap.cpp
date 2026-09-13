class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        int ans = 0;

        for(int i = -(n-1); i<n; i++){
            for(int j = -(n-1); j<n; j++){
                int cnt = 0;
                
                for(int r = 0; r<n; r++){
                    int nr = (i+r);
                    if(nr>=n || nr<0) continue;

                    for(int c = 0; c<n; c++){
                        int nc = (j+c);

                        if(nc>=n || nc<0) continue;
                        if(img1[nr][nc] & img2[r][c]) cnt++;  
                    }
                }

                ans = max(cnt, ans);
            }
        }

        return ans;
    }

};