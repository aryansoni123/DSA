class Solution {
public:

    pair<string, int> helper(int i, string &s){
        int n = s.size();

        string tmp = "";

        while(i<n && s[i]!=')'){
            if(s[i] == '('){
                auto [val, j] = helper(++i, s);
                i = j;
                tmp+=val;
            } else{
                if(i<n && s[i]!=')') tmp+=s[i];
                i++;
            }
        }


        reverse(tmp.begin(), tmp.end());
        // cout<<tmp;
        // reverse(tmp.begin(), tmp.begin() + tmp.size()/2);
        // reverse(tmp.end() - tmp.size()/2, tmp.end());

        return {tmp, ++i};
    }

    string reverseParentheses(string s) {

        int n = s.size();
        int i = 0;

        string ans = "";

        while(i<n){
            if(s[i] == '('){
                auto [val, j] = helper(++i, s);
                ans+=val;
                i = j;
            } else{
                ans+=s[i];
                i++;
            }
        }

        // auto [ans, i] = helper(1, s);
        // cout<<i;
        
        return ans;
        // return "";
    }


    /*
         
    
    
    
    */
};