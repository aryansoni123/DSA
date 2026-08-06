class Solution {
public:

    int isPossible(int mid, int k, vector<int>& nums){
        int cap = 0;
        int cnt = 1;

        for(auto x: nums){
            if(cap + x <= mid){
                cap+=x;
            } else{
                cap = x;
                // k--;
                cnt++;

                // if(k==0) return true;
            }
        }
        // k--;

        return cnt<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = 0, h = 0;

        // if(k>nums.size()) return -1

        for( auto x: nums){
            l = max(l, x);
            h += x;
        }

        while(l<=h){
            int m = l + (h-l)/2;

            if(isPossible(m, k, nums)){
                h = m - 1;
            } else{
                l = m + 1;
            }
        }

        return l;
    }
};