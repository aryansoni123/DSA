class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int m1 = 0, m2 = 0;

        for(auto x:nums){
            if(x>=m1){
                m2 = m1;
                m1 = x;
            } else if(x<m1 && x>m2){
                m2 = x;
            }
        }

        cout<<m1<<m2;

        // sort(nums.begin(), nums.end());
        
        // return (nums[n-1]-1)*(nums[n-2]-1);
        return (m1-1)*(m2-1);

    }
};