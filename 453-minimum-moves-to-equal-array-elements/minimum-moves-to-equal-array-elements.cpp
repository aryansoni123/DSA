class Solution {
public:
    int minMoves(vector<int>& nums) {

        int n = nums.size();

        int mn = INT_MAX;

        for(auto x: nums)
            mn = min(mn, x);

        int ans = 0;

        for(auto x: nums)
            ans+= x-mn;

        return ans;
        
    }
};