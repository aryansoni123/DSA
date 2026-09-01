class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // map<char, int> mpp1;
        map<char, char> mpp;

        int n = s.size();

        for(int i= 0; i<n; i++){
            // for(auto &p: mpp){
            //     if(p.second == t[i] && p.first!=s[i]) return false;
            // }

            if(!mpp.contains(s[i])){
                mpp[s[i]] = t[i];
                for(auto &p: mpp){
                    if(p.second == t[i] && p.first!=s[i]) return false;
                }
            } else{
                if(mpp[s[i]] != t[i]) return false;
                for(auto &p: mpp){
                    if(p.second == t[i] && p.first!=s[i]) return false;
                }
            }
        }

        return true;
    }
};