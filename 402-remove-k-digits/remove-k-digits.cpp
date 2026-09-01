class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;

        int m = num.size();

        if(k==m) return "0";

        for(auto x: num){
            int val = x - '0';

            if(st.empty()){
                st.push(val);
            } else{
                while(!st.empty() && st.top()>val && k>0){
                    // if(st.top()>val) k--;
                    st.pop();
                    k--;
                } 

                st.push(val);
            }
        }

        string ans;

        while(k>0){
            st.pop();
            k--;
        }

        while(!st.empty()){
            ans+= (char)st.top() + '0';
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;

        while(ans[i]=='0') i++;


        int n = ans.size();

        // cout<<k<<' '<<ans;

        return ans.substr(i, n-i-k) == "" ? "0" : ans.substr(i, n-i-k);
    }
};