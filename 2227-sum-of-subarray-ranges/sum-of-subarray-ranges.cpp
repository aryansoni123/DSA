class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;

        vector<int> nse(n, n);
        vector<int> nge(n, n);
        vector<int> pse(n, -1);
        vector<int> pge(n, -1);

        stack<int> st;

        // PSE

        for(int i = 0; i<n; i++){
            if(st.empty()) st.push(i);

            else{
                while(!st.empty() && nums[st.top()] >= nums[i]){
                    st.pop();
                }

                if(!st.empty()) pse[i] = st.top();

                st.push(i);
            }
        }

        // PGE

        st = {};

        for(int i = 0; i<n; i++){
            if(st.empty()) st.push(i);

            else{
                while(!st.empty() && nums[st.top()] < nums[i]){
                    st.pop();
                }

                if(!st.empty()) pge[i] = st.top();

                st.push(i);
            }
        }

        // nse

        st = {};

        for(int i = n-1; i>=0; i--){
            if(st.empty()) st.push(i);

            else{
                while(!st.empty() && nums[st.top()] > nums[i]){
                    st.pop();
                }

                if(!st.empty()) nse[i] = st.top();

                st.push(i);
            }
        }

        // NGE

        st = {};

        for(int i = n-1; i>=0; i--){
            if(st.empty()) st.push(i);

            else{
                while(!st.empty() && nums[st.top()] <= nums[i]){
                    st.pop();
                }

                if(!st.empty()) nge[i] = st.top();

                st.push(i);
            }
        }

        for(int i = 0; i<n; i++){
            long long leftMin  = i - pse[i];
            long long rightMin = nse[i] - i;

            long long leftMax  = i - pge[i];
            long long rightMax = nge[i] - i;

            ans += 1LL * nums[i] * leftMax * rightMax;
            ans -= 1LL * nums[i] * leftMin * rightMin;
        }

        return ans;
    }
};