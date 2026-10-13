class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr;

        for(int i = 0; i<n; i++){
            arr.push_back(abs(nums[i]));
        }

        sort(arr.begin(), arr.end());

        long long ans = 0;

        for(int i = 0; i<n/2; i++){
            ans-=(1LL*arr[i]*arr[i]);
        }

        for(int i = n/2; i<n; i++){
            ans+=(1LL*arr[i]*arr[i]);
        }

        return ans;
    }
};