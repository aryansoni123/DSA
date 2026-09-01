class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> st;

        int m = num.size();

        if(k==m) return "0";

        for(auto x: num){
            int val = x - '0';

            if(st.empty()){
                st.push_back(val);
            } else{
                while(!st.empty() && st.back()>val && k>0){
                    st.pop_back();
                    k--;
                } 

                st.push_back(val);
            }
        }

        string ans;

        while(k>0){
            st.pop_back();
            k--;
        }

        for(auto x: st){
            ans+= (char)x + '0';
            // st.pop();
        }

        // reverse(ans.begin(), ans.end());

        int i = 0;

        while(ans[i]=='0') i++;

        int n = ans.size();

        return ans.substr(i, n-i) == "" ? "0" : ans.substr(i, n-i);
    }
};