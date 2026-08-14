class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0;
        int n = s.size();
        int ans = 0;

        map<char, int> mpp;

        for(int i = 0; i<n; i++){
            mpp[s[r]]++;

            while (mpp[s[r]]>2){
                mpp[s[l]]--;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};