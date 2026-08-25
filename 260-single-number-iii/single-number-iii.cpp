class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long n = 0;

        for(auto x: nums) n^=x;

        int p = 0;

        while(true){
            long long val = (long long)(n & (1LL<<p));

            if(val>0) break;

            p++;
        }

        // int mul = (n&(n-1))^n;

        // int mul = n&(-n);

        int mul = 1<<p;

        int val1 = 0, val2 = 0;

        for(auto x: nums){
            if(x&mul) val1^=x;
            else val2^=x;
        }

        return {val1, val2};
    }
};