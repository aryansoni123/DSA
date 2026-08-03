class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        
        int l = 1;
        int h = n-2;

        int mid = 0;

        while (l<=h){
            mid = l+(h-l)/2;

            if((nums[mid] == nums[mid-1]) || (nums[mid] == nums[mid+1])){
                if (mid%2 == 0){
                    if (nums[mid] == nums[mid-1]) h=mid-1;
                    else l=mid+1;
                }

                else if(mid%2==1){
                    if (nums[mid] == nums[mid-1]) l=mid+1;
                    else h=mid-1;
                }
            }
            
            else{
                return nums[mid];
            } 
        }

        return -1;
    }
};