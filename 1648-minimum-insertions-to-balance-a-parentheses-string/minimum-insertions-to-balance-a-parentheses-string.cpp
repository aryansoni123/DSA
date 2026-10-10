class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        int ans = 0;

        int open = 0;
        int close = 0;

        int n = s.size();

        int i = 0;

        stack<char> st;

        // for(auto x: s){
        while(i<n){
            if(s[i] == '(') st.push(s[i]);
            else{
                if(i!=n-1 && s[i+1]== ')'){
                    if(!st.empty() && st.top() == '('){
                        st.pop();
                    } else{
                        ans+=1;
                    }
                    i++;
                } else{
                    if(!st.empty() && st.top() == '('){
                        st.pop();
                        ans+=1;
                    } else{
                        ans+=2;
                    }
                    // st.pop();
                }
            }

            i++;
        }

        while(!st.empty()){
            ans+=2;
            st.pop();
        }

        // while(i<n){
        //     if(s[i] == '(') open+=2;
        //     else close++;

        //     if(open == close){
        //         open = 0;
        //         close = 0;
        //     }

        //     if(close>open){
        //         if(i!=n-1 && s[i+1]== ')'){
        //             ans+=1;
        //             i++;
        //         }
        //         else{
        //             ans+=2;

        //         }
        //         close = 0;
        //         open = 0;
        //     }

        //     i++;
        // }

        return ans;
    }
};