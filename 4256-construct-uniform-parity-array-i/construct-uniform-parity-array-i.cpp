class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        bool ans = true;

        // bool it = true;

        for(int i = 0; i<n; i++){
            bool it = true;

            if(nums1[i]%2) continue;

            for(int j = 0; j<n; j++){
                bool it = false;

                if(i!= j && (nums1[i] - nums1[j])%2){
                    break;
                }
            }

            ans = ans&it;
        }

        if(ans) return ans;

        ans = true;

        for(int i = 0; i<n; i++){
            bool it = true;

            if(nums1[i]%2 == 0) continue;

            for(int j = 0; j<n; j++){
                bool it = false;

                if(i!= j && (nums1[i] - nums1[j])%2 == 0){
                    break;
                }
            }

            ans = ans&it;
        }

        return ans;
    }
};