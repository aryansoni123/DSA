class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0];
        int cnt = 2;

        vector<int> ans;

        for(auto x: nums){
            if(curr!=x){
                ans.push_back(x);
                curr = x;
                cnt = 1;

            } else{
                if(cnt){
                    ans.push_back(x);
                    cnt--;
                }

            }
        }

        int n = ans.size();

        for(int i = 0; i<n; i++){
            nums[i] = ans[i];
        }

        cout<<n;

        return n;

    }
};