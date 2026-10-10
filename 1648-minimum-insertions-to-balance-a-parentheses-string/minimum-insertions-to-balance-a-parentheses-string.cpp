class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int n = s.size();

        int i = 0;

        stack<char> st;

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
                }
            }

            i++;
        }

        // while(!st.empty()){
        //     ans+=2;
        //     st.pop();
        // }

        return ans + 2*st.size();
    }
};