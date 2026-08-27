class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mpp;
        stack<int> st;

        for(int i = nums2.size() - 1; i>=0; i--){
            int x = nums2[i];
            if(st.empty()){
                mpp[x] = -1;
                st.push(x);
            } else{
                while(!st.empty() && st.top()<x){
                    st.pop();
                }

                mpp[x] = st.empty() ? -1 : st.top();
                st.push(x);
            }
        }

        vector<int> ans;

        for(auto x: nums1){
            ans.push_back(mpp[x]);
        }

        return ans;
    }
};