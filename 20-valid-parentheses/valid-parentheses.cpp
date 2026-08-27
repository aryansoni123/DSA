class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto x: s){
            if(x == '(' || x == '[' || x == '{') st.push(x);

            else{
                if(st.empty()) return false;
                else if(x==')' && st.top() == '(') st.pop();
                else if(x==']' && st.top() == '[') st.pop();
                else if(x=='}' && st.top() == '{') st.pop();
                else return false;
            }
        }

        // while(!st.empty()){
        //     cout<<st.top();
        //     st.pop();
        // }


        return st.size() == 0;

    }
};