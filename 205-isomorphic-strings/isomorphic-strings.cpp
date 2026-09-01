class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // map<char, int> mpp1;
        map<char, char> mpp;

        int n = s.size();

        for(int i= 0; i<n; i++){
    
            if(mpp.contains(s[i])){
                if(mpp[s[i]] != t[i]) return false;
        
            } else{
                for(auto &p: mpp){
                    if(p.second == t[i] && p.first!=s[i]) return false;
                }
    
            mpp[s[i]] = t[i];
    
            }
        }

        return true;
    }
};