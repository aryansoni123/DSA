class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int l = 0, r = 1;
        int n = nums.size();

        int ans = 0, xor1 = 0;
        bool zero = false;

        for(auto num: nums){
            xor1 ^= num;

            if(num!=0) zero = true;
        }

        if(xor1!=0) return n;
        else return zero ? n-1 : 0;

        // return ans;
    }
};