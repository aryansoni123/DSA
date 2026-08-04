class Solution {
public:

    bool isPossible(int mid, int threshold, vector<int> &nums){
        int totsum = 0;

        for(double x: nums){
            double div = ceil(x/mid);
            totsum+=div;
        }

        cout<<totsum<<endl;

        if(totsum<=threshold) return true;
        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int mx = INT_MIN, mn = INT_MAX;

        for(auto x:nums){
            mx = max(mx, x);
            mn = min(mn, x);
        }
        int low = 1, high = mx, ans = mx;

        while(low<=high){
            int mid = low+(high-low)/2;

            if(isPossible(mid, threshold, nums)){
                ans = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }

        return low;

    }
};