class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int i = 0;

        if(n==1) return 1;

        int ans = 0;

        vector<int> prev(n, 1);
        vector<int> nxt(n, 1);

        while(i<n){
            int j = n-1-i;

            if(i>0){
                if(ratings[i]>ratings[i-1]){
                    prev[i] = prev[i-1] + 1;
                } else{
                    prev[i] = 1;
                }
            }

            if(j<n-1){
                if(ratings[j]>ratings[j+1]){
                    nxt[j] = nxt[j+1] + 1;
                } else{
                    nxt[j] = 1;
                }
            }
            
            i++;
        }

        i = 0;

        while(i<n){
            ans+=max(prev[i], nxt[i]);
            i++;
        }

        return ans;
    }
};