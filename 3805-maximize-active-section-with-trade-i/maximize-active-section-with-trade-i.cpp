class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ini = 0;
        vector<int> zeros;

        for(char c: s) if(c == '1') ini++;

        int i = 0, cnt = 0, prev = 0;
        int mx = 0;

        while (i<n){
            if (s[i] == '0') cnt++;

            else if(s[i] == '1' && cnt!= 0){
                if (prev == 0){
                    prev = cnt; 
                    cnt = 0;
                    continue;
                }
                mx = max(prev+cnt, mx);
                prev = cnt;
                cnt = 0;
                // cnt = 0
                // zeros.push_back(cnt);
            }
            i++;
        }

        if(prev!=0 && cnt!=0) mx = max(prev+cnt, mx);
        // if (cnt!=0) zeros.push_back(cnt);
        // cout<<zeros.size();

        // if(zeros.size() == 1) return ini;

        // for(int i: zeros) cout<<i;

        // for(int i = 1; i<zeros.size(); i++){
        //     mx = max(zeros[i-1]+zeros[i], mx);
        // }
        cout<<ini;
        return mx+ini;
    }
};