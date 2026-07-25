class Solution {
public:
    int maxProduct(int n) {
        vector<int> s;

        while (n>0){
            s.push_back(n%10);
            n/=10;
        }

        int mx = 0;

        sort(s.begin(), s.end());

        // for(auto x: s) cout<<x;

        for(int i = 1; i<s.size(); i++){
            mx = max(mx,s[i-1]*s[i]);
        }

        return mx;
    }
};