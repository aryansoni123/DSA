class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = strs[0];

        int pt = ans.size();

        for(auto x: strs){
            for(int i = 0; i<pt; i++){
                if(x[i] != ans[i]){
                    pt = i;
                    break;
                }
            }
        }

        return ans.substr(0, pt);
    }
};