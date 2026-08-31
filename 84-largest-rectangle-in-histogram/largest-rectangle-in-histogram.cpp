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

            // if(pse[i] == -1 && nse[i] == -1){
            //     ans = max(ans, heights[i]);
            //     continue;
            // }

            int l = 0, r = 0, hl = INT_MAX, hr = INT_MAX;

            // if(pse[i]!=-1) l = i-pse[i];
            // if(nse[i]!=-1) r = nse[i]-i;

            int dist = nse[i] - pse[i] - 1;

            if(pse[i]!=-1) hl = heights[pse[i]];
            if(nse[i]!=-1) hr = heights[nse[i]];

            int h = min(min(hl, hr), heights[i]);

            // ans = max(ans, max(dist*h, heights[i]));
            ans = max(ans, dist*heights[i]);
        }

        return ans;
    }
};