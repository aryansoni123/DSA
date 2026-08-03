class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0, h = n-1;

        while(l<h){
            int m = l + (h-l)/2;

            if(nums[l]>nums[m]){
                h = m; // pick smallest from right sorted half and discard the rest
            } else if(nums[h]<nums[m]){
                l = m + 1;
            } else{
                return nums[l];
            }
        }
        return nums[l];
    }
};