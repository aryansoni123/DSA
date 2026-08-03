class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        if (nums.size()<1) return {-1,-1};

        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        cout<<first<<' '<<last;

        if(first<n && last<n && 0<=first && 0<=last && nums[first] == target && nums[last] == target) return {first, last};
        return {-1,-1};
    }
};