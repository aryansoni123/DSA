class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // map<char, int> mpp1;
        map<char, char> mpp;

        int n = s.size();

        for(int i= 0; i<n; i++){
            for(auto &p: mpp){
                if(p.second == t[i] && p.first!=s[i]) return false;
            }

            if(!mpp.contains(s[i])){
                mpp[s[i]] = t[i];
            } else{
                if(mpp[s[i]] != t[i]) return false;
            }

            // cout<<s[i]<<' '<<mpp[s[i]];
            // cout<<endl;
        }

        // for(auto x: mpp){
        //     cout<<x.first<<' '<<x.second;
        //     cout<<endl;
        // }

        return true;
    }
};