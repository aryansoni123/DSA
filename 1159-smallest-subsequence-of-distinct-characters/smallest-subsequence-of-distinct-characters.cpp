class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> ind(26);
        vector<int> seen(26);
        string ans;

        for(int i = 0; i<s.size(); i++) ind[s[i] - 'a'] = i;
        char c;

        for(int i = 0; i<s.size(); i++){
            c = s[i];
            if (seen[c - 'a']) continue;

            while (ans.size() && ans.back() > c && ind[ans.back() - 'a'] > i){
                seen[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            seen[c - 'a'] = 1;
            ans.push_back(c);
        }

        return ans;
    }
};