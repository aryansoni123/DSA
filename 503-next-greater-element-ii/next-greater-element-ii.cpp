class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        vector<int> mpp(n, 0);
        stack<int> st;

        int mx = INT_MIN;
        int ind = 0;
        int cnt = 0;

        while(cnt<2*n){

            while(!st.empty() && st.top()<=nums[ind]){
                st.pop();
            }

            if(st.empty()){
                st.push(nums[ind]);
                mpp[ind] = -1;
            } else{
                mpp[ind] = st.top();
                st.push(nums[ind]);
            }

            cnt++;
            ind = ind == 0 ? n-1 : ind-1;
        }

        return mpp;

    }
};