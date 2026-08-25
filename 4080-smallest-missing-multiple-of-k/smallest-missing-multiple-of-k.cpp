class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int, int> mpp;

        for(auto x: nums) mpp[x]++;

        for(int i = k; i<=200; i=i+k){
            if(mpp[i] == 0) return i;
        }

        return -1;
    }
};