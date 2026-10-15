class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        unordered_set<int> dist;

        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                dist.insert(nums[j]);
                int m = dist.size();
                ans+= m*m;
            }
            dist.clear();
        }

        return ans;
    }
};