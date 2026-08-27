class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if(n<=2) return 0;

        vector<int> pref(n, 0);
        vector<int> suff(n, 0);

        pref[0] = -1;
        pref[1] = height[0];

        for(int i = 2; i<n; i++){
            pref[i] = max(pref[i-1], height[i-1]);
        }

        suff[n-1] = -1;
        suff[n-2] = height[n-1];

        for(int i = n-3; i>=0; i--){
            suff[i] = max(suff[i+1], height[i+1]);
        }

        int ans = 0;

        for(int i = 0; i<n; i++){
            int val = min(pref[i], suff[i]) - height[i];

            if(val>0) ans+=val;
        }

        return ans;
    }
};