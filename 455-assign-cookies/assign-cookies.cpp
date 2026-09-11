class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort(s.begin(), s.end());
        // reverse(s.begin(), s.end());

        // sort(g.begin(), g.end());
        // reverse(g.begin(), g.end());

        sort(s.begin(), s.end(), greater<int>());
        sort(g.begin(), g.end(), greater<int>());

        int i = 0, j = 0;

        int n = s.size();
        int m = g.size();

        while(i<n && j<m){
            if(s[i]>=g[j]){
                i++;
                j++;
            } else{
                j++;
            }
        }

        return i;
    }
};