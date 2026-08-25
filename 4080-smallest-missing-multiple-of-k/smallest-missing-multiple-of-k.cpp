class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int, int> mpp;
        vector<int> freq(101, 0);

        for(auto x: nums) freq[x] = 1;

        int i = k;

        while(i<=100){
            if(!freq[i]) return i;

            i+=k;
        }

        return i;

        // for(int i = k; i<=200; i=i+k){
        //     if(mpp[i] == 0) return i;
        // }

        // return -1;
    }
};