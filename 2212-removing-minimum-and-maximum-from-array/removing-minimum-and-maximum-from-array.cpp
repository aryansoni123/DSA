class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX, mx = INT_MIN;
        int mind = 0, Mind = 0;

        int n = nums.size();

        for(int i = 0; i<n; i++){
            if(nums[i] < mini){
                mini = nums[i];
                mind = i;
            }

            if(nums[i] > mx){
                mx = nums[i];
                Mind = i;
            }
        }

        int a = min(mind, Mind);
        int b = max(mind, Mind);

        int left = b +1;
        int right = n-a;
        int both = a+1 + n-b;

        return min(both, min(left, right));

    }
};