class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> arr = nums;

        sort(nums.begin(), nums.end());

        int ans = -1;

        for(int i = 0; i<nums.size(); i++){
            if(arr[i] != nums[i]){
                ans = ans & arr[i];
            }
        }

        return ans==-1 ? 0 : ans;
    }
};