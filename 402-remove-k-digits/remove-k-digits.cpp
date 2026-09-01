class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        int m = num.size();

        if(k==m) return "0";

        for(auto x: num){
            if(st.empty()){
                st.push_back(x);
            } else{
                while(!st.empty() && st.back()>x && k>0){
                    st.pop_back();
                    k--;
                } 

                st.push_back(x);
            }
        }

        string ans;

        while(k>0){
            st.pop_back();
            k--;
        }

        // for(auto x: st){
        //     ans+= x ;
        // }

        int i = 0;

        while(st[i]=='0') i++;

        int n = st.size();

        return st.substr(i, n-i) == "" ? "0" : st.substr(i, n-i);
    }
};