class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        vector<int> mpp(n, 0);
        stack<int> st;

        int mx = INT_MIN;
        int ind = -1;
        int cnt = 0;

        for(int i = 0; i<n; i++){
            if(nums[i]>mx){
                mx = nums[i];
                ind = i;
                cnt=1;
            } else if(nums[i] == mx) cnt++;
        }

        // mpp[mx] = -1;

        cnt = 0;

        // ind = ind == 0 ? n-1; ind-1;

        // cout<<mx;
        // cout<<endl;
        // cout<<ind;
        // cout<<endl;
        // cout<<cnt;

        while(cnt<n){

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