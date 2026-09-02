class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mno = INT_MAX;
        int mne = INT_MAX;

        for(auto x: nums1){
            if(x%2){
                mno = min(mno, x);
            } else{
                mne = min(mne, x);
            }
        }

        if(mno == INT_MAX) return true;

        return mno<=mne;
    }
};