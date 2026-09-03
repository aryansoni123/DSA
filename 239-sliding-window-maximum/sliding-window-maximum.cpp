class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int mx = INT_MIN;

        int n = nums.size();

        if(k==n){
            for(auto x: nums) mx = max(x, mx);
            return {mx};
        }

        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i<k; i++){
            if(dq.empty()) dq.push_back(i);

            else{
                while(!dq.empty() && nums[dq.back()] < nums[i]){
                    dq.pop_back();
                }

                dq.push_back(i);
            }
        }

        ans.push_back(nums[dq.front()]);

        int win = 1;

        for(int i = k; i<n; i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            dq.push_back(i);

            while(dq.front()<win) dq.pop_front();

            // for(auto x: dq) cout<<nums[x]<<' ';
            // cout<<endl;
            ans.push_back(nums[dq.front()]);
            win++;
        }


        return ans;
    }
};