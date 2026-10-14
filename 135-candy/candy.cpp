class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int i = 0;

        if(n==1) return 1;

        int ans = 0;
        // int prev = 1;

        vector<int> prev(n);
        vector<int> nxt(n);

        while(i<n){
            if(i==0){
                if(ratings[i] <= ratings[i+1]) prev[0] = 1;
                else{
                    prev[0] = 2;
                }
            }

            else if(i==n-1){
                if(ratings[i] <= ratings[i-1]) prev[n-1] = 0;
                else{
                    prev[i] = prev[i-1] + 1;
                    // prev[n-1] = 2;
                }
            }

            else{
                // if(ratings[i]>ratings[i+1] || ratings[i]>ratings[i-1]){
                if(ratings[i]>ratings[i-1]){
                    prev[i] = prev[i-1] + 1;
                // } else if(ratings[i] = ratings[i-1]){
                //     prev[i] = 1;
                //     // ans+=prev;
                } else{
                    prev[i] = 1;
                }
            }

            i++;
        }

        i--;

        while(i>=0){
            if(i==0){
                if(ratings[i] <= ratings[i+1]) nxt[i] = 1;
                else{
                    nxt[i] = nxt[i+1] + 1;
                    // nxt[i] = 2;
                    // ans+=2;
                }
            }

            else if(i==n-1){
                if(ratings[i] <= ratings[i-1]) nxt[i] = 1;
                else{
                    nxt[i] = 2;
                    // prev = 2;
                    // ans+=2;
                }
            }

            else{
                // if(ratings[i]>ratings[i+1] || ratings[i]>ratings[i-1]){
                if(ratings[i]>ratings[i+1]){
                    // ans+= ++prev;
                    nxt[i] = nxt[i+1] + 1;
                // } 
                // else if(ratings[i] == ratings[i+1]){
                //     nxt[i] = 1;
                //     // ans+=prev;
                } else{
                    nxt[i] = 1;
                    // ans+= --prev;
                    // prev = 1;
                }
            }

            i--;
        }

        // int cnt = 0;
        // for(auto x: prev){
        //     cout<<x<<' ';
        //     cnt+=x;
        // }
        // cnt = 0;
        // cout<<cnt;
        // cout<<endl;
        // for(auto x: nxt){
        //     cout<<x<<' ';
        //     cnt+=x;
        // }
        // cout<<cnt;

        i = 0;

        while(i<n){
            ans+=max(prev[i], nxt[i]);
            i++;
        }

        return ans;
    }
};