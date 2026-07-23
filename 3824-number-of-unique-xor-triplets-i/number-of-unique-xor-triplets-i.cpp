class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int m, n = nums.size();

        if (n == 1) return 1;
        else if (n==2) return 2;

        for(int i = 1; i<=17; i++){
            if (n<=pow(2,i) && n>=pow(2,i-1)) m = i;
        }

        return pow(2,m);
    }
};