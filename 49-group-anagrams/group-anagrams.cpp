class Solution {
public:

    vector<int> createMap(string s){
        vector<int> mpp(26, 0);

        for(auto x: s){
            mpp[x-'a']++;
        }

        return mpp;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<vector<int>, vector<int>> mpp;
        map<vector<int>, vector<string>> mpp;

        for(auto s: strs){
            mpp[createMap(s)].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto x: mpp){
            ans.push_back(x.second);
        }

        return ans;
    }
};