class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = 0;

        for(auto x: nums){
            mx = max(mx, x);
        }

        int ans = 0;

        for(auto x: nums){
            ans+= mx-x;
        }

        return ans;
    }
};