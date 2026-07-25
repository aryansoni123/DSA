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

        int m = s.size();

        // for(int i = 1; i<s.size(); i++){
        //     mx = max(mx,s[i-1]*s[i]);
        // }

        return s[m-1]*s[m-2];
    }
};