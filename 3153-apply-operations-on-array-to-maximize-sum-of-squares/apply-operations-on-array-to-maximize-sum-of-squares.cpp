class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int l = 0;

        int mx = 0;

        int MOD = 1000000007;

        for(auto x: nums) mx = max(x, mx);

        while(mx>0){
            l++;
            mx>>=1;
        }

        vector<int> vals(l, 0);

        for(auto x: nums){
            int plc = l-1;
            while(x>0){
                if(x&1){
                    vals[plc]++;
                }

                x>>=1;
                plc--;
            }
        }

        // for(auto x: vals) cout<<x<<' ';

        long long ans = 0;

        int i = 0;

        while(i<k){
            int plc = l-1;

            int val = 0;

            for(int j = 0; j<l; j++){
                if(vals[j]){
                    val |= (1 << plc);
                    vals[j]--;
                }
                plc--;
            }

            // cout<<endl;
            // cout<<val;
            // cout<<endl;
            // for(auto x: vals) cout<<x<<' ';

            ans+= (1LL*val*val)%MOD;
            i++;
        }

        return ans%MOD;
    }
};