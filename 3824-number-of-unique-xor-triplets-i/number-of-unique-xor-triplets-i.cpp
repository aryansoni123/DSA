class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        set<int> s;

        int n = nums.size();
        // int val = nums[0];
        int m;

        if (n == 1) return 1;
        else if (n==2) return 2;

        // for(auto x:nums) s.insert(x);

        for(int i = 1; i<=17; i++){
            if (n<=pow(2,i) && n>=pow(2,i-1)) m = i;
        }

        cout<<m;
        long long a = pow(2, m);
        return a;
    }
};