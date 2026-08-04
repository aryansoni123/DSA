class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        if(k<arr[0]) return k;

        int l = 0, h = n-1;

        while(l<=h){
            int m = l+(h-l)/2;

            int miss = arr[m] - m - 1;

            if(miss<k){
                l = m+1;
            } else{
                h = m - 1;
            }
        }

        return k + h + 1;
    }
};