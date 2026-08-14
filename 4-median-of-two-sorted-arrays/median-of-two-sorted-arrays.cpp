class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        int l = 0, r= 0;

        int n = nums1.size();
        int m = nums2.size();

        while(l<n && r<m){
            if(nums1[l]<nums2[r]) {
                ans.push_back(nums1[l]);
                l++;
            } else{
                ans.push_back(nums2[r]);
                r++;
            }
        }

        while(l<n){
            ans.push_back(nums1[l]);
            l++;
        }
        while(r<m){
            ans.push_back(nums2[r]);
            r++;
        }

        n = ans.size();

        // cout<<n;

        // for(auto x: ans) cout<<x<<' ';

        // cout<<endl;

        if(n%2){
            return ans[n/2];
        } else{
            // cout<<ans[n/2]<<' '<<ans[n/2+1];
            return (double)(ans[n/2] + ans[n/2-1])/2;
        }
    }
};