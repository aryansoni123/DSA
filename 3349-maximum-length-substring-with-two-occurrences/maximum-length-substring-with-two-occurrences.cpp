class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0;
        int n = s.size();
        int ans = 0;

        // map<char, int> mpp;
        vector<int> freq(26, 0);

        for(int i = 0; i<n; i++){
            freq[s[i] - 'a']++;

            while (freq[s[i] - 'a']>2){
                freq[s[l] - 'a']--;
                l++;
            }

            ans = max(ans, i-l+1);
            // r++;
        }

        return ans;
    }
};