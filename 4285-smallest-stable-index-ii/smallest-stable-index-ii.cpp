class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pref(n+1, 0);
        vector<int> suff(n+1, 0);

        pref[0] = nums[0];
        suff[n] = nums[n-1];

        for(int i = 0; i<n; i++){
            pref[i+1] = max(pref[i], nums[i]);
            suff[n-i-1] = min(suff[n-i], nums[n-i-1]);
        }

        for(int i = 0; i<n; i++){
            if(pref[i+1]-suff[i] <= k) return i;
        }

        return -1;
    }
};