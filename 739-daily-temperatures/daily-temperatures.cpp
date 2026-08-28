class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;

        int n = temperatures.size();

        vector<int> ans(n, 0);

        for(int i = n-1; i>=0; i--){
            int x = temperatures[i];

            while(!st.empty() && temperatures[st.top()]<=x){
                st.pop();
            }

            if(st.empty()){
                st.push(i);
            } else{
                ans[i] = st.top()-i;
                st.push(i);
            }
        }

        return ans;

    }
};