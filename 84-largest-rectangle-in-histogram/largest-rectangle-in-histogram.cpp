class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;

        int n = heights.size();

        vector<int> pse(n, -1);

        for(int i = 0; i<n; i++){
            if(st.empty()) st.push(i);

            else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }

                if(!st.empty()) pse[i] = st.top();

                st.push(i);
            }
        }

        st = {};

        vector<int> nse(n, n);

        for(int i = n-1; i>=0; i--){
            if(st.empty()) st.push(i);

            else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }

                if(!st.empty()) nse[i] = st.top();

                st.push(i);
            }
        }

        int ans = 0;

        for(int i = 0; i<n; i++){

            int dist = nse[i] - pse[i] - 1;

            ans = max(ans, dist*heights[i]);
        }

        return ans;
    }
};