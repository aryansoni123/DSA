class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ini = 0;
        vector<int> zeros;

        for(char c: s) if(c == '1') ini++;

        int i = 0, cnt = 0;

        while (i<n){
            if (s[i] == '0') cnt++;

            else if(s[i] == '1' && cnt!= 0){
                zeros.push_back(cnt);
                cnt = 0;
            }
            i++;
        }

        if (cnt!=0) zeros.push_back(cnt);
        // cout<<zeros.size();

        if(zeros.size() == 1) return ini;
        int mx = 0;


        // for(int i: zeros) cout<<i;

        for(int i = 1; i<zeros.size(); i++){
            mx = max(zeros[i-1]+zeros[i], mx);
        }

        return mx+ini;
    }
};