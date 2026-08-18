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
                int key = it.first;
                int val = it.second;

                // cout<<key<<' '<<val<<endl;

                if(val == 1) ans = max(ans, key);
            }

            return ans;
        }

        else{
            int last = nums[n-1];
            int first = nums[0];

            if(mpp[last]!=1 && mpp[first]!=1) return -1;
            
            else if(mpp[first] == 1 && mpp[last] == 1){
                return max(last, first);
            }

            else if(mpp[last]>1) return first;
            else if(mpp[first]>1) return last;
        }

        return -1;

    }
};