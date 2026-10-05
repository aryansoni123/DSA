class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();

        stack<int> st;

        // if(s == "((((((())))()())))") return

        for(int i = 0; i<n; i++){
            if(s[i] == '(') st.push(0);

            else{
                if(st.top() == 0){
                    st.pop();
                    st.push(1);
                } else{
                    int val = 0;
                    int cnt = 0;

                    while(st.top() != 0){
                        val+=st.top();
                        st.pop();
                        cnt++;
                    }
                    st.pop();
                    st.push(2*val);
                }
            }
        }

        int ans = 0;

        while(!st.empty()){
            // cout<<st.top();
            ans+=st.top();
            st.pop();
            cout<<endl;
        }

        return ans;
    }
};