class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        int n = s.size();

        for(int i = 0; i<n; i++){
            int pos = 26 - (s[i] - 'a');

            int prod = pos * (i+1);

            ans+=prod;
        }

        return ans;
    }
};