class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx = 0, mn = 101, n = nums.size();

        for(auto x: nums){
            mx = max(x, mx);
            mn = min(x, mn);
        }

        vector<int> seen(mx-mn+1, 0);

        for(auto x: nums){
            seen[x-mn] = 1;
        }

        vector<int> ans;

        for(int i = 0; i<seen.size(); i++){
            if(seen[i] == 0) ans.push_back(i+mn);
        }

        return ans;
    }
};