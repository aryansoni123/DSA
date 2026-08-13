class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for(auto x: nums){
            if(x>0) pos.push_back(x);
            else neg.push_back(x);
        }

        int n = nums.size();

        vector<int> ans(n, 0);

        for(int i = 0; i<n; i++){
            if(i%2 == 0) ans[i] = pos[i/2];
            else ans[i] = neg[i/2];
        }

        return ans;
    }
};