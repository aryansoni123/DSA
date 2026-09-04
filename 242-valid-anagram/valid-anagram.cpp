class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sf(26, 0);
        vector<int> tf(26, 0);

        for(auto x: s) sf[x - 'a']++;
        for(auto x: t) tf[x - 'a']++;

        for(int i = 0; i<26; i++){
            if(sf[i] != tf[i]) return false;
        }

        return true;
    }
};