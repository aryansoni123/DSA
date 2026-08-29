class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        const long long MOD = 1e9 + 7;

        int n = arr.size();

        vector<int> pse(n, -1);
        vector<int> nse(n, n);

        stack<int> st;

        for(int i = 0; i<n; i++){
            if(st.empty()) st.push(i);

            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }

                if(!st.empty()) pse[i] = st.top();
                
                st.push(i);
            }
        }
        
        st = {};
        
        for(int i = n-1; i>=0; i--){
            if(st.empty()) st.push(i);

            else{
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }

                if(!st.empty()) nse[i] = st.top();
                    
                st.push(i);
            }
        }

        long long ans = 0;

        for(int i = 0; i<n; i++){
            long long val = ((long long)(i-pse[i]) * (nse[i]-i) * arr[i]) % MOD;
            ans += val;
            ans%=MOD;
        }

        return ans%MOD;
    }
};