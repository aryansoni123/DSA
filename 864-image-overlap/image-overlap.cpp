class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        int ans = 0;

        for(int i = -(n-1); i<n; i++){
            for(int j = -(n-1); j<n; j++){
                int cnt = 0;
                // int cnt2 = 0;
                // int cnt3 = 0;
                // int cnt4 = 0;
                for(int r = 0; r<n; r++){
                    int nr = (i+r);
                    if(nr>=n || nr<0) continue;

                    for(int c = 0; c<n; c++){
                        int nc = (j+c);

                        if(nc>=n || nc<0) continue;
                        if(img1[nr][nc] & img2[r][c]) cnt++;  //DR
                        // if(img2[nr][nc] & img1[r][c]) cnt2++; //UL
                        // if(img1[nr][c] & img2[r][nc]) cnt3++; //DL
                        // if(img2[r][nc] & img1[nr][c]) cnt4++; //UR
                    }
                }

                // int mx = max(max(cnt, cnt2), max(cnt3, cnt4));

                ans = max(cnt, ans);
            }
        }

        return ans;
    }

};