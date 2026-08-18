class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        int mx = 0;
        map<int, int> mpp;

        for(auto x: nums){
            mx = max(x, mx);
            mpp[x]++;
        }

        if(k==n) return mx;

        int ans = -1;

        if(k == 1){
            for(auto it: mpp){
                int val = it.first;
                int freq = it.second;

                if(freq == 1) 
                    ans = max(ans, val);
            }

            return ans;
        }

        int last = nums[n-1];
        int first = nums[0];

        if (mpp[nums[0]] == 1)
            ans = max(ans, nums[0]);

        if (mpp[nums[n-1]] == 1)
            ans = max(ans, nums[n-1]);

        // if(mpp[last]!=1 && mpp[first]!=1) return -1;
        
        // else if(mpp[first] == 1 && mpp[last] == 1){
        //     return max(last, first);
        // }

        // else if(mpp[last]>1) return first;
        // else if(mpp[first]>1) return last;

        return ans;

    }
};