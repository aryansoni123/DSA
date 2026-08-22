class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int cnt = 1;

        int i = 0, j= 0;

        int num = pow(n, 2);

        while(cnt<=num){
            while(j<n && cnt<=num){
                ans[i][j] = cnt;
                cnt++;
                j++;

                if(j<n && ans[i][j]!=0){
                    // j--;
                    break;
                }
            }

            j--;
            i++;

            while(i<n && cnt<=num){
                ans[i][j] = cnt;
                cnt++;
                i++;

                if(i<n && ans[i][j] != 0){
                    // i--;
                    break;
                }
            }
            i--;
            j--;


            while(j>=0 && cnt<=num){
                // cout<<'a'<<cnt<<endl;
                ans[i][j] = cnt;
                cnt++;
                j--;
                if(j>=0 && ans[i][j] != 0){
                    // j++;
                    break;
                } 
            }
            j++;
            i--;
            // cout<<i<<' '<<j<<' '<<cnt<<endl;

            while(i>=0 && cnt<=num){
                // cout<<'a'<<i<<' '<<j<<' '<<cnt<<endl;
                ans[i][j] = cnt;
                cnt++;
                i--;

                if(i>=0 && ans[i][j]!=0){
                    // i++;
                    break;
                } 
            }
            i++;
            j++;
        }

        return ans;
    }
};