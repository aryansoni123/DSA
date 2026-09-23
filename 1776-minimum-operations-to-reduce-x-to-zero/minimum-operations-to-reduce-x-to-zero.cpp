class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int req = 0;

        for(auto x: nums) req+=x;
        req-=x;

        int l = 0, r = 0;
        int ans = -1;
        int sum = 0;

        while(r<n){
            req-=nums[r];

            while(l<=r && req<0){
                req+=nums[l];
                l++;
            }

            if(req == 0) ans = max(ans, r-l+1);
            r++;
        }

        return ans == -1 ? ans : n - ans;
    }
};