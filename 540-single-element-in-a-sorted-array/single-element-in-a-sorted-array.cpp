class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;

        int mid = 0;

        while (l<=h){
            mid = (l+h)/2;

            if((0<mid && nums[mid] == nums[mid-1]) || (mid<=n-2 && nums[mid] == nums[mid+1])){
                if (mid%2 == 0){
                    if (nums[mid] == nums[mid-1]) h--;
                    else l++;
                }

                else if(mid%2==1){
                    if (nums[mid] == nums[mid-1]) l++;
                    else h--;
                }
            }
            
            else{
                return nums[mid];
            } 
        }

        return -1;
    }
};