class Solution {
public:

    int isPossible(int mid, int k, vector<int>& nums){
        int cap = 0;

        for(auto x: nums){
            if(cap + x <= mid){
                cap+=x;
            } else{
                cap = x;
                k--;            
            }
        }
        k--;

        return k>=0;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = 0, h = 0;

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