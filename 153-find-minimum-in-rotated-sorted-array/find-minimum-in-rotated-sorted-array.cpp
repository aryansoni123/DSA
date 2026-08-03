class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0, h = n-1;

        while(l<h){
            int m = l + (h-l)/2;

            if(nums[l]>nums[m]){
                h = m;
            } else if(nums[h]<nums[m]){
                l = m + 1;
            } else{
                break;
            }
        }

        return nums[l];
    }
};