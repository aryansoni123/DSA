class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int ma = 0, mi = 1001;

        for(auto it: nums){
            ma = max(it, ma);
            mi = min(it, mi);
        }

        // cout<< ma<< ' '<< mi<< endl;

        return gcd(ma, mi);
    }
};