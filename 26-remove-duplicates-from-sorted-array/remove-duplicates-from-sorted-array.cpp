class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 101;

        vector<int> ans;

        for(auto x: nums){
            if(x!=curr){
                curr = x;
                ans.push_back(x);
            }
        }

        for(int i = 0; i<ans.size(); i++){
            nums[i] = ans[i];
        }

        return ans.size();
    }
};