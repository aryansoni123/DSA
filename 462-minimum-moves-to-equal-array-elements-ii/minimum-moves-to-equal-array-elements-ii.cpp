class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int med1 = 0, med2 = 0;

        int n = nums.size();

        if(n%2){
            med1 = nums[n/2];
            med2 = med1;
        } else{
            med1 = nums[n/2];
            med2 = nums[n/2 - 1];
        }

        int res1 = 0, res2 = 0;

        for(auto x: nums){
            res1 += abs(x-med1);
            res2 += abs(x-med2);
        }

        return min(res1, res2);
    }
};